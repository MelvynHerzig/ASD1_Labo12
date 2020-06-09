/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : taquinSolver.h
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 But         : Implémente une classe permettant la résolution d'un jeu de taquin.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ASD1_LABO11_TAQUINSOLVER_H
#define ASD1_LABO11_TAQUINSOLVER_H

#include <vector> // std::vector
#include <array>  // std::array
#include <map>    // std::map

#include <iostream> // std::cout, std::cin, std::endl


const unsigned DIMENSION  = 3;
const unsigned EMPTY_CELL = 0;

using element = unsigned;
using Grid    = std::array<element, DIMENSION*DIMENSION>;
using Grids   = std::vector<Grid>;
using GridMap = std::map<Grid, Grid*>;


class TaquinSolver
{
public:

   /**
    * @brief Saved state of grid to solve.
    */
   Grid initialGrid;

   /**
    * @brief Contains multiple grid state with their parents.
    */
   GridMap gridMap;

   /**
    * @brief Default constructor.
    */
   TaquinSolver();

   /**
    * @brief Lit le flux d'entrée et remplit la configuration initialState.
    */
   void initConfig();

   /**
    * @brief From the initial configuration searches the shortest way to solve the puzzle.
    */
   void solveConfig();

private:

   /**
    * @brief For a given grid, check if it is solved.
    * @param grid[in] Grid to check.
    * @return True if solved else false.
    */
   static bool isSolved(const Grid& grid);

   /**
    * @brief Fill the gridMap with iterations of
    */
   void generateBFS();

   /**
    * @brief For a given grid, create the next possibles plays.
    * @param grid[in] Grid to generate next states.
    * @return Vector of generated grids.
    */
   Grids generateNextState(const Grid& grid) const;

   /**
    * @brief For a given index on the grid, determines if it is on first row.
    * @param position Index of a cell on the grid.
    * @return True if on first row
    */
   static bool isFirstRow(size_t position);

   /**
    * @brief For a given index on the grid, determines if it is on last row.
    * @param position Index of a cell on the grid.
    * @return True if on last row
    */
   static bool isLastRow(size_t position);

   /**
    * @brief For a given index on the grid, determines if it is on first column.
    * @param position Index of a cell on the grid.
    * @return True if on first column.
    */
   static bool isFirstCol(size_t position);

   /**
    * @brief For a given index on the grid, determines if it is on last column.
    * @param position Index of a cell on the grid.
    * @return True if on last column.
    */
   static bool isLastCol(size_t position);

};


#endif //ASD1_LABO11_TAQUINSOLVER_H
