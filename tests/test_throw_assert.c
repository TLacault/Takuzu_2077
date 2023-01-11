#include "takuzu.h"

bool test_throw_error() {
    return false;
}

bool test_game_test() {
    return false;
}

bool test_cgame_test() {
    return false;
}

bool test_pointer_test() {
    return false;
}

/*  USAGE  */
void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

/*  MAIN ROUTINE  */
int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argv);

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool pass = false;
    if (strcmp("throw_error", argv[1]) == 0)
        pass = test_throw_error();
    else if (strcmp("game_test", argv[1]) == 0)
        pass = test_game_test();
    else if (strcmp("cgame_test", argv[1]) == 0)
        pass = test_cgame_test();
    else if (strcmp("pointer_test", argv[1]) == 0)
        pass = test_pointer_test();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (pass == true) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}