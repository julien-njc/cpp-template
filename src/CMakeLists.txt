
# Grab public headers list
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/utilities/memory.hpp)

# Create a library - can be linked dynamically or statically
add_library(${MY_PROJECT_LIB} error.cpp utilities/memory.cpp ${HEADER_LIST})

# Add include path dependency for current directory
target_include_directories(${MY_PROJECT_LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add include path dependency on public includes
target_include_directories(${MY_PROJECT_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# This library is a C 11 
target_compile_features(${MY_PROJECT_LIB} PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
