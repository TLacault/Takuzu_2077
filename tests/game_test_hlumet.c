#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"
#include "game_ext.h"

bool test_game_set_square() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    squares[DEFAULT_SIZE * 0 + 0] = S_ZERO;
    game_set_square(g, 1, 0, S_ONE);
    squares[DEFAULT_SIZE * 1 + 0] = S_ONE;
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    squares[DEFAULT_SIZE * 0 + 3] = S_IMMUTABLE_ZERO;
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    squares[DEFAULT_SIZE * 1 + 5] = S_IMMUTABLE_ONE;
    game_set_square(g, 0, 1, S_EMPTY);
    squares[DEFAULT_SIZE * 0 + 1] = S_EMPTY;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            if (game_get_square(g, i, j) != squares[DEFAULT_SIZE * i + j])
                return (false);
        }
    }
    game_delete(g);
    return (true);
}

bool test_game_get_square() {
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 1, 0, S_ONE);
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    game_set_square(g, 0, 1, S_EMPTY);
    if (game_get_square(g, 0, 0) != S_ZERO)
        status = false;
    else if (game_get_square(g, 1, 0) != S_ONE)
        status = false;
    else if (game_get_square(g, 0, 3) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_square(g, 1, 5) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_square(g, 0, 1) != S_EMPTY)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_number() {
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 3, S_ONE);
    game_set_square(g, 0, 4, S_ZERO);
    if (game_get_number(g, 0, 1) != 1)
        status = false;
    else if (game_get_number(g, 0, 0) != -1)
        status = false;
    else if (game_get_number(g, 2, 1) != 0)
        status = false;
    else if (game_get_number(g, 0, 3) != 1)
        status = false;
    else if (game_get_number(g, 0, 4) != 0)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_next_square() {
    game g = game_default();
    game g2 = game_new_empty_ext(7, 14, true, false);
    bool status = true;

    if (!g || !g2)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    game_set_square(g2, 0, 2, S_ONE);
    game_set_square(g2, 1, 2, S_ONE);
    if (game_get_next_square(g, 0, 0, RIGHT, 1) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 0, RIGHT, 2) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 0, DOWN, 1) != S_EMPTY)
        status = false;
    else if (game_get_next_square(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_square(g, 2, 1, UP, 2) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 1, RIGHT, 2) != S_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 5, LEFT, 1) != S_ONE)
        status = false;
    else if (game_get_next_square(g2, 0, 14, RIGHT, 2) != S_ONE)
        status = false;
    else if (game_get_next_square(g2, 7, 2, DOWN, 1) != S_ONE)
        status = false;
    game_delete(g);
    game_delete(g2);
    return (status);
}

bool test_game_get_next_number() {
    game g = game_default();
    game g2 = game_new_empty_ext(7, 14, true, false);
    bool status = true;

    if (!g || !g2)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    game_set_square(g2, 0, 2, S_ONE);
    game_set_square(g2, 1, 2, S_ONE);
    if (game_get_next_number(g, 0, 0, RIGHT, 1) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 0, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 0, DOWN, 1) != -1)
        status = false;
    else if (game_get_next_number(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_number(g, 2, 1, UP, 2) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 1, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 5, LEFT, 1) != 1)
        status = false;
    else if (game_get_next_number(g2, 0, 14, RIGHT, 2) != 1)
        status = false;
    else if (game_get_next_number(g2, 7, 2, DOWN, 1) != 1)
        status = false;
    game_delete(g);
    game_delete(g2);
    return (status);
}

bool test_game_nb_rows(void) {
    bool status = true;
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};

    square squares2[12 * 12] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0,
                                0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    square squares3[7 * 4] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 0};
    game g = game_new(squares);
    game g2 = game_new_ext(12, 12, squares2, false, false);
    game g3 = game_new_ext(7, 4, squares3, false, false);
    if (!g || !g2 || !g3)
        return false;
    if (game_nb_rows(g) != 6 || game_nb_rows(g2) != 12 || game_nb_rows(g3) != 7)
        status = false;
    game_delete(g);
    game_delete(g2);
    game_delete(g3);
    return status;
}

bool test_game_nb_cols(void) {
    bool status = true;
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};

    square squares2[12 * 12] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0,
                                0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    square squares3[7 * 4] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 4, 0, 0, 0, 0, 0, 4, 0};
    game g = game_new(squares);
    game g2 = game_new_ext(12, 12, squares2, false, false);
    game g3 = game_new_ext(7, 4, squares3, false, false);
    if (!g || !g2 || !g3)
        return false;
    if (game_nb_cols(g) != 6 || game_nb_cols(g2) != 12 || game_nb_cols(g3) != 4)
        status = false;
    game_delete(g);
    game_delete(g2);
    game_delete(g3);
    return status;
}

void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argv);

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool ok = false;
    if (strcmp("game_set_square", argv[1]) == 0)
        ok = test_game_set_square();
    else if (strcmp("game_get_square", argv[1]) == 0)
        ok = test_game_get_square();
    else if (strcmp("game_get_number", argv[1]) == 0)
        ok = test_game_get_number();
    else if (strcmp("game_get_next_square", argv[1]) == 0)
        ok = test_game_get_next_square();
    else if (strcmp("game_get_next_number", argv[1]) == 0)
        ok = test_game_get_next_number();
    else if (strcmp("game_nb_rows", argv[1]) == 0)
        ok = test_game_nb_rows();
    else if (strcmp("game_nb_cols", argv[1]) == 0)
        ok = test_game_nb_cols();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}