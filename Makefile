GEN ?= cmake
BUILD_TYPE ?= Debug
BUILD_DIR=$(CURDIR)/_build/$(GEN)/$(BUILD_TYPE)
INSTL_DIR=$(CURDIR)/_install/$(GEN)/$(BUILD_TYPE)

# all: cmake_install
all: cmake_test

CMAKE_OPTIONS = -H$(CURDIR)
CMAKE_OPTIONS += -B$(BUILD_DIR)
CMAKE_OPTIONS += -DCMAKE_INSTALL_PREFIX=$(INSTL_DIR)

ifeq ($(GEN), xcode)
	CMAKE_OPTIONS += -G "Xcode"
else
	CMAKE_OPTIONS += -G "Unix Makefiles"
endif

ifeq ($(BUILD_TYPE), Debug)
	CMAKE_OPTIONS += -DCMAKE_INSTALL_PREFIX=/home/user/workspace/github/Catch2/_install/lib/cmake
	CMAKE_OPTIONS += -DCMAKE_VERBOSE_MAKEFILE=ON
	CMAKE_OPTIONS += -DCMAKE_BUILD_TYPE=Debug
else
	CMAKE_OPTIONS += -DCMAKE_BUILD_TYPE=Release
endif

cmake_config:
	cmake $(CMAKE_OPTIONS)

cmake_build: cmake_config
	cmake --build $(BUILD_DIR)

ifeq ($(BUILD_TYPE), Debug)
ifeq ($(GEN), xcode)
cmake_test: cmake_build
	open $(BUILD_DIR)/CPP_Practice.xcodeproj
else
cmake_test: cmake_build
	export ASAN_OPTIONS=verify_asan_link_order=0
	cmake --build $(BUILD_DIR) --target test
	cat $(BUILD_DIR)/Testing/Temporary/LastTest.log
endif

cmake_install: cmake_test
else
cmake_install: cmake_build
endif
	cmake --build $(BUILD_DIR) --target install

clean:
	rm -rf $(BUILD_DIR) $(INSTL_DIR)
