set(EXTRA_COMPONENT_DIRS "oasis")

if(DEFINED ENV{OASIS_FLAVOR})
    set(OASIS_FLAVOR $ENV{OASIS_FLAVOR})
else()
    set(OASIS_FLAVOR "debug")
endif()

if(OASIS_FLAVOR STREQUAL "debug")
    message(STATUS "🔧 Oasis Build: Debug Mode")
    set(SDKCONFIG_DEFAULTS "sdkconfig.debug")
else()
    message(STATUS "🔧 Oasis Build: Release Mode")
    set(SDKCONFIG_DEFAULTS "sdkconfig.release")
endif()

# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(oasis)

