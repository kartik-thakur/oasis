cmake_minimum_required(VERSION 3.16)

# The following boilerplate is required for ESP-IDF to function properly
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(oasis)

# Extra component directory
set(EXTRA_COMPONENT_DIRS "oasis")

# Detect build flavor from environment variable, fallback to debug
if(DEFINED ENV{OASIS_FLAVOR})
    set(OASIS_FLAVOR $ENV{OASIS_FLAVOR})
else()
    set(OASIS_FLAVOR "debug")
endif()

# Start with the shared defaults
set(SDKCONFIG_DEFAULTS "sdkconfig.defaults")

# Append flavor-specific defaults
if(OASIS_FLAVOR STREQUAL "debug")
    message(STATUS "🔧 Oasis Build: Debug Mode")
    list(APPEND SDKCONFIG_DEFAULTS "sdkconfig.debug")
elseif(OASIS_FLAVOR STREQUAL "release")
    message(STATUS "🚀 Oasis Build: Release Mode")
    list(APPEND SDKCONFIG_DEFAULTS "sdkconfig.release")
elseif(OASIS_FLAVOR STREQUAL "qemu")
    message(STATUS "💻 Oasis Build: QEMU Emulation Mode")
    list(APPEND SDKCONFIG_DEFAULTS "sdkconfig.debug" "sdkconfig.qemu")
else()
    message(FATAL_ERROR "❌ Unknown OASIS_FLAVOR: ${OASIS_FLAVOR}")
endif()
