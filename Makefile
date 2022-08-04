LIB = f1.cstructs

BUILD_DIR = build

YEAR = $(shell date +'%Y')
VERSION = $(shell date +'%Y.%m.%d')
JAVA_SOURCES_PATH = $(BUILD_DIR)/src/main/java

INCLUDE_DIR = src/include
C_API_FILE = $(INCLUDE_DIR)/capi.h

UNAME_S = $(shell uname -s)
STDLIB_INCLUDE = /usr/include
ifeq ($(UNAME_S), Darwin)
	STDLIB_INCLUDE = /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
endif

MAVEN_FLAGS = -Dversion=$(VERSION) -Dsrc.dir=$(JAVA_SOURCES_PATH)

all: clean jar

dump-stdlib:
	jextract --source -t f1.specs.datatypes -I $(STDLIB_INCLUDE) $(STDLIB_INCLUDE)/stdlib.h $(args)

java-src:
	jextract --source -t f1.cstructs.year$(YEAR) -I $(STDLIB_INCLUDE) -I $(INCLUDE_DIR)/$(YEAR) --header-class-name c_api --output $(JAVA_SOURCES_PATH) $(args) $(C_API_FILE)

src: clean
	$(MAKE) java-src args='--dump-includes dump.txt'
	$(MAKE) dump-stdlib args="--dump-includes stdlib.txt"
	python scripts/diff.py dump.txt stdlib.txt
	$(MAKE) java-src args="@diff.txt"

jar: src
	mvn clean package $(MAVEN_FLAGS)

deploy: src
	mvn deploy $(MAVEN_FLAGS)

clean:
	rm -fr *.txt
	rm -fr $(BUILD_DIR)
	mvn clean $(MAVEN_FLAGS)
