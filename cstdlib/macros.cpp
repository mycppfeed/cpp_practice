#include <stdio.h>
#include <cstdlib>

#ifndef NDEBUG

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#endif

int return_exit_code(int code) {
    return (code == EXIT_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}

#ifdef NDEBUG
void print_help_exit(char *argv0) {
    printf("Usage:\n\t %s <code>\n\n Where, code can be 0 for EXIT_SUCCESS or 1 for EXIT_FAILURE\n", argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) print_help_exit(argv[0]);

    return return_exit_code(atoi(argv[1]));
}
#else
TEST_CASE( "Return Success or Failure Exit codes", "[exit_code]" ) {
    REQUIRE( return_exit_code(0) == EXIT_SUCCESS );
    REQUIRE( return_exit_code(1) == EXIT_FAILURE );
}
#endif