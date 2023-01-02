#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"
#include "game_ext.h"

void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

bool test_game_is_immutable() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_is_immutable(g, i, j) &&
                (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            } else if (!(game_is_immutable(g, i, j)) &&
                       (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_has_error() {
    game g1 = game_default_solution();
    square squares_2[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2,
                                                     4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3};
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_2, false, false);
    if (!g1 || !g2)
        return false;

    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_has_error(g1, i, j) || !game_has_error(g2, i, j)) {
                game_delete(g1);
                game_delete(g2);
                return false;
            }
        }
    }
    game_delete(g1);
    game_delete(g2);

    square squares_3[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                     0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g3 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_3, true, false);
    square squares_4[DEFAULT_SIZE * DEFAULT_SIZE] = {2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2,
                                                     2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2};
    game g4 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_4, false, true);
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (!game_has_error(g3, i, j) || !game_has_error(g4, i, j)) {
                game_delete(g3);
                game_delete(g4);
                return false;
            }
        }
    }
    game_delete(g3);
    game_delete(g4);
    return true;
}

bool test_game_check_move() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_check_move(g, i, j, S_EMPTY) &&
                (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            } else if (!(game_check_move(g, i, j, S_EMPTY)) &&
                       (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_play_move() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return (false);
    square q;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            q = game_get_square(g, i, j);
            if (q == S_IMMUTABLE_ONE || q == S_IMMUTABLE_ZERO) {
                break;
            } else {
                game_play_move(g, i, j, S_ONE);
            }
            if ((q == S_IMMUTABLE_ONE || q == S_IMMUTABLE_ZERO) && q != game_get_square(g, i, j)) {
                game_delete(g);
                return false;
            }
            if ((q != S_IMMUTABLE_ONE && q != S_IMMUTABLE_ZERO) && q == game_get_square(g, i, j)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_is_over() {
    game g1 = game_default_solution();
    square squares_2[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2, 3, 3, 4, 4, 1, 1,
                                                     2, 2, 3, 3, 4, 4, 1, 1, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2};
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_2, false, false);
    square squares_3[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2,
                                                     4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3};
    game g3 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_3, false, false);
    square squares_4[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 2, 3, 4, 1, 2, 3,
                                                     4, 1, 2, 3, 4, 1, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    game g4 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_4, false, false);
    square squares_5[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1,
                                                     1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0};
    game g5 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_5, false, false);

    if (!g1 || !g2 || !g3 || !g4 || !g5)
        return false;

    if (!game_is_over(g1) || game_is_over(g2) || game_is_over(g3) || game_is_over(g4) || game_is_over(g5)) {
        game_delete(g1);
        game_delete(g2);
        game_delete(g3);
        game_delete(g4);
        game_delete(g5);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    game_delete(g5);
    return true;
}

bool test_game_is_unique(void) {
    game g1 = game_new_empty_ext(8, 8, false, true);
    game g2 = game_new_empty_ext(8, 8, false, false);
    if (!game_is_unique(g1) || game_is_unique(g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    return true;
}

bool test_game_is_wrapping(void) {
    game g1 = game_new_empty_ext(8, 8, true, false);
    game g2 = game_new_empty_ext(8, 8, false, false);
    if (!game_is_wrapping(g1) || game_is_wrapping(g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argv);

    bool ok = false;
    if (strcmp(argv[1], "game_is_immutable") == 0)
        ok = test_game_is_immutable();
    else if (strcmp(argv[1], "game_has_error") == 0)
        ok = test_game_has_error();
    else if (strcmp(argv[1], "game_check_move") == 0)
        ok = test_game_check_move();
    else if (strcmp(argv[1], "game_play_move") == 0)
        ok = test_game_play_move();
    else if (strcmp(argv[1], "game_is_over") == 0)
        ok = test_game_is_over();
    else if (strcmp(argv[1], "game_is_unique") == 0)
        ok = test_game_is_unique();
    else if (strcmp(argv[1], "game_is_wrapping") == 0)
        ok = test_game_is_wrapping();
    else {
        fprintf(stderr, "Error: test \"%s\" not found\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (ok) {
        fprintf(stderr, "Test: \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test: \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}