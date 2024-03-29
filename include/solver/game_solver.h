/**
 * @file game_solver.h
 * @brief Game Solver.
 * @details See @ref index for further details.
 * @copyright University of Bordeaux. All rights reserved, 2023.
 *
 **/

#ifndef __GAME_SOLVER_H
#define __GAME_SOLVER_H
#include <stdbool.h>
#include <stdio.h>

#include "game.h"

/* ************************************************************************** */
/*                                DATA TYPES                                  */
/* ************************************************************************** */

/**
 * @brief Coordinates Type
 * @details This is an opaque data type.
 */
struct coordinates_s {
    uint i;
    uint j;
};

/**
 * @brief The structure pointer that stores the coordinates of a square.
 **/
typedef struct coordinates_s *coordinates;

/**
 * @brief Solver structure.
 * @details This is an opaque data type.
 */
struct solver_s {
    coordinates *coords; /** the coordinates of the empty squares */
    uint len;            /** the length of the word */
    uint nb_zero;        /** the number of zeros in the word */
    uint nb_one;         /** the number of ones in the word */
    uint nb_solutions;   /** the number of solutions found */
    bool unique;         /** true if the solver has to find only 1 solution */
    square *solution;    /** the first solution */
};

/**
 * @brief The structure pointer that stores the solver state.
 **/
typedef struct solver_s *solver;

/**
 * @brief The structure constant pointer that stores the solver state.
 * @details That means that it is not possible to modify the solver using this pointer.
 **/
typedef const struct solver_s *csolver;

/* ************************************************************************** */
/*                                MACRO                                       */
/* ************************************************************************** */

#define COORDS_I(s, pos) ((s)->coords[(pos)]->i)
#define COORDS_J(s, pos) ((s)->coords[(pos)]->j)

/* ************************************************************************** */
/*                                FUNCTIONS                                   */
/* ************************************************************************** */

/**
 * @name Game Solver
 * @{
 */

/**
 * @brief Initialize a solver for a game.
 * @param g Game
 * @param unique True if the solver has to find only 1 solution
 * @return A new solver
 */
solver solver_new(game g, bool unique);

/**
 * @brief Delete a solver.
 * @param s Solver
 */
void solver_delete(solver s);

/**
 * @brief Find all solutions of a game
 * @param g Game
 * @param s Solver
 * @param pos Position in the word
 */
void find_solutions(game g, solver s, uint pos);

/**
 * @brief Check if a word is a solution
 * @param g Game
 * @param s Solver
 */
bool is_word_solution(game g, solver s);

/**
 * @brief Copy the solution of a game from a solver
 * @param g Game
 * @param s Solver
 */
void copy_solution(game g, csolver s);

/**
 * @brief Print a word
 * @param g Game
 * @param solver Solver
 */
void print_word(cgame g, csolver s);

#endif  // __GAME_SOLVER_H__