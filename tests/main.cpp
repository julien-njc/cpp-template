#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

extern "C" const char *__asan_default_options() {
    return "allocator_may_return_null=1";
}
