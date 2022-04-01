# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.8)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

# Create the tests app
add_executable(tests main.cpp utilities.cpp) 

# Add project lib
target_link_libraries(tests PRIVATE ${MY_PROJECT_LIB})

# Add catch2
target_link_libraries(tests PRIVATE Catch2::Catch2)

# This app is a C 11 app
target_compile_features(tests PRIVATE cxx_std_17)
