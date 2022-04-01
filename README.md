c-template

---

# VS Extensions

On M1 you will need to use the CppLLDB extension.

Also useful to use Code debugging capability is the CMake tools for VS Code. Then go in the tool, set an active target, it will be run by the launch configuration.

# Dependencies

There are 2 dependencies to the template:

1. Doxygen: this is used to generate a documentation of the library public header files (include folder)
2. Catch2: unit test framework imported using FetchContent

# Leak detection

Using `leaks` will display leaks in your application,

Example: `leaks -atExit -- ./build/tests/tests | grep LEAK:`
