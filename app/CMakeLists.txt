# Create executable
add_executable(${MY_PROJECT_APP} main.c)

# Should be linked to the cstring library
target_link_libraries(${MY_PROJECT_APP} PRIVATE ${MY_PROJECT_LIB})

# This app is a C 11 app
target_compile_features(${MY_PROJECT_APP} PRIVATE c_std_11)
