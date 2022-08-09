LIB = f1.cstructs

BUILD_DIR = build

YEAR = $(shell date +'%Y')
VERSION = $(shell date +'%Y.%m.%d')
JAVA_SOURCES_PATH = $(BUILD_DIR)/src/main/java

INCLUDE_DIR = src/include

UNAME_S = $(shell uname -s)
STDLIB_INCLUDE = /usr/include
ifeq ($(UNAME_S), Darwin)
	STDLIB_INCLUDE = /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
endif

MAVEN_FLAGS = -Dversion=$(VERSION) -Dsrc.dir=$(JAVA_SOURCES_PATH)

all: clean jar

patch-root:
	sed 's/PACK/f1.cstructs.year$(year)/g' 'src/Constants$$root.java' > $(JAVA_SOURCES_PATH)/$(shell echo 'f1.cstructs.year$(year)' | tr '.' '/')/Constants\$$root.java

dump-stdlib:
	jextract --source -t f1.specs.datatypes -I $(STDLIB_INCLUDE) $(STDLIB_INCLUDE)/stdlib.h $(args)

jextracting:
	jextract --source -t f1.cstructs.year$(year) -I $(STDLIB_INCLUDE) -I $(INCLUDE_DIR) -I $(INCLUDE_DIR)/$(year) --header-class-name c_api --output $(JAVA_SOURCES_PATH) $(args) $(INCLUDE_DIR)/capi.h

collect-src:
	$(MAKE) jextracting year=$(year) args='--dump-includes dump.txt'
	$(MAKE) dump-stdlib args="--dump-includes stdlib.txt"
	python scripts/diff.py dump.txt stdlib.txt
	$(MAKE) jextracting year=$(year) args="@diff.txt"
	$(MAKE) patch-root year=$(year)

java-src: clean
	$(MAKE) collect-src year=2021
	$(MAKE) collect-src year=2022

jar:
	$(MAKE) java-src
	mvn clean package $(MAVEN_FLAGS)

deploy: java-src
	mvn deploy $(MAVEN_FLAGS)

clean:
	rm -fr *.txt
	rm -fr $(BUILD_DIR)
	mvn clean $(MAVEN_FLAGS)
