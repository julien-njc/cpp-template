cmake_minimum_required(VERSION 3.19)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# TODO: Set your projects specifics
set(MY_PROJECT cpp-template)
set(MY_PROJECT_VERSION 0.1)
set(MY_PROJECT_DESCRIPTION "Starter template to work with a full C environment")
set(MY_PROJECT_LIB cpptemplate)
set(MY_PROJECT_APP cpptemplate_app)

project(${MY_PROJECT}
    VERSION ${MY_PROJECT_VERSION}
    DESCRIPTION ${MY_PROJECT_DESCRIPTION})

# let's build in native arm
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)

# Testing only available if this is the main app
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  add_subdirectory(tests)
endif()
