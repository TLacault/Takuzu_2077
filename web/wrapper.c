/**
 * @file wrapper.js
 * @brief Game Binding to JavaScript (based on Emscripten & Wasm)
 * @author aurelien.esnard@u-bordeaux.fr
 * @copyright University of Bordeaux. All rights reserved, 2022.
 **/

#include <emscripten.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "takuzu.h"

/* ******************** Game V1 & V2 API ******************** */

EMSCRIPTEN_KEEPALIVE
game new_default(void) { return game_default(); }

EMSCRIPTEN_KEEPALIVE
void delete(game g) { game_delete(g); }

EMSCRIPTEN_KEEPALIVE
square get_square(cgame g, uint i, uint j) { return game_get_square(g, i, j); }

EMSCRIPTEN_KEEPALIVE
void play_move(game g, uint i, uint j, square s) { game_play_move(g, i, j, s); }

EMSCRIPTEN_KEEPALIVE
bool check_move(cgame g, uint i, uint j, square s) { return game_check_move(g, i, j, s); }

EMSCRIPTEN_KEEPALIVE
void restart(game g) { game_restart(g); }

EMSCRIPTEN_KEEPALIVE
bool is_over(game g) { return game_is_over(g); }

EMSCRIPTEN_KEEPALIVE
uint nb_rows(cgame g) { return game_nb_rows(g); }

EMSCRIPTEN_KEEPALIVE
uint nb_cols(cgame g) { return game_nb_cols(g); }

EMSCRIPTEN_KEEPALIVE
int get_number(cgame g, uint i, uint j) { return game_get_number(g, i, j); }

EMSCRIPTEN_KEEPALIVE
bool is_empty(cgame g, uint i, uint j) { return game_is_empty(g, i, j); }

EMSCRIPTEN_KEEPALIVE
bool is_immutable(cgame g, uint i, uint j) { return game_is_immutable(g, i, j); }

EMSCRIPTEN_KEEPALIVE
int has_error(cgame g, uint i, uint j) { return game_has_error(g, i, j); }

EMSCRIPTEN_KEEPALIVE
void undo(game g) { game_undo(g); }

EMSCRIPTEN_KEEPALIVE
void redo(game g) { game_redo(g); }

/* ******************** Game Tools API ******************** */

EMSCRIPTEN_KEEPALIVE
bool solve(game g) { return game_solve(g); }

EMSCRIPTEN_KEEPALIVE
uint nb_solutions(cgame g) { return game_nb_solutions(g); }

EMSCRIPTEN_KEEPALIVE
solver solver_new(game g, bool unique) { return solver_new(g, unique); }

EMSCRIPTEN_KEEPALIVE
void solver_delete(solver s) { solver_delete(s); }

EMSCRIPTEN_KEEPALIVE
void find_solutions(game g, solver s, uint pos) { find_solutions(g, s, pos); }

EMSCRIPTEN_KEEPALIVE
bool is_word_solution(game g, solver s) { return is_word_solution(g, s); }

EMSCRIPTEN_KEEPALIVE
void copy_solution(game g, csolver s) { copy_solution(g, s); }

/* ******************** Game Other ******************** */

EMSCRIPTEN_KEEPALIVE
game new_random(uint nb_rows, uint nb_cols, bool wrapping, bool uniq) {
    srand(time(NULL));  // random seed
    return game_random(nb_rows, nb_cols, wrapping, uniq, false);
}

// EOF