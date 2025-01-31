LIB = f1.cstructs

BUILD_DIR = build

YEAR = $(shell date +'%Y')
VERSION = $(shell date +'%Y.%m.%d-%H')
JAVA_SOURCES_PATH = $(BUILD_DIR)/src/main/java

INCLUDE_DIR = src/include

UNAME_S = $(shell uname -s)
STDLIB_INCLUDE = /usr/include
ifeq ($(UNAME_S), Darwin)
	STDLIB_INCLUDE = /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
endif

MAVEN_FLAGS = -Drevision=$(VERSION) -Dsrc.dir=$(JAVA_SOURCES_PATH)
MVN = mvn

all: clean jar

patch-root:
	sed 's/PACK/$(package)/g' 'src/Constants$$root.java' > $(JAVA_SOURCES_PATH)/$(shell echo '$(package)' | tr '.' '/')/Constants\$$root.java

dump-stdlib:
	jextract -t f1.specs.datatypes -I $(STDLIB_INCLUDE) $(STDLIB_INCLUDE)/stdlib.h $(args)

jextracting:
	jextract -t f1.cstructs.year$(year).version$(major_version)_$(minor_version) -I $(STDLIB_INCLUDE) -I $(INCLUDE_DIR) -I $(INCLUDE_DIR)/$(year)/$(major_version)/$(minor_version) --header-class-name capi --output $(JAVA_SOURCES_PATH) $(args) $(INCLUDE_DIR)/$(year)/$(major_version)/$(minor_version)/capi.h

jextracting-packet-header:
	jextract  -t f1.cstructs -I $(STDLIB_INCLUDE) -I $(INCLUDE_DIR) --output $(JAVA_SOURCES_PATH) $(args) $(INCLUDE_DIR)/BasePacketHeader.h

collect-packet-header:
	$(MAKE) jextracting-packet-header args='--include-struct BasePacketHeader'
	$(MAKE) patch-root package=f1.cstructs

generate-exports-dump:
	$(MAKE) jextracting year=$(year) major_version=$(major_version) minor_version=$(minor_version) args='$(include_arg) --dump-includes dump.txt'
	$(MAKE) dump-stdlib args="--dump-includes stdlib.txt"
	python3 scripts/diff.py dump.txt stdlib.txt
	mv diff.txt $(INCLUDE_DIR)/$(year)/$(major_version)/$(minor_version)/exports.txt
	rm -fr stdlib.txt

collect-packets:
	$(MAKE) jextracting year=$(year) major_version=$(major_version) minor_version=$(minor_version) args="$(include_arg) @$(INCLUDE_DIR)/$(year)/$(major_version)/$(minor_version)/exports.txt"
	$(MAKE) patch-root package=f1.cstructs.year$(year).version$(major_version)_$(minor_version)
	rm -fr *.txt

java-src: clean
	# $(MAKE) collect-packets year=2021 major_version=1 minor_version=17
	# $(MAKE) collect-packets year=2021 major_version=1 minor_version=19 include_arg="-I $(INCLUDE_DIR)/2021/1/17"
	
	# $(MAKE) collect-packets year=2022 major_version=1 minor_version=8
	# $(MAKE) collect-packets year=2022 major_version=1 minor_version=9
	$(MAKE) collect-packets year=2022 major_version=1 minor_version=12

	$(MAKE) collect-packets year=2023 major_version=1 minor_version=12 include_arg="-I $(INCLUDE_DIR)/2022/1/8"

	$(MAKE) collect-packet-header

jar: java-src
	$(MVN) clean package $(MAVEN_FLAGS)

jar-src: jar
	$(MVN) source:jar $(MAVEN_FLAGS)

clean:
	rm -fr *.txt
	rm -fr $(BUILD_DIR)
	$(MVN) clean $(MAVEN_FLAGS)
