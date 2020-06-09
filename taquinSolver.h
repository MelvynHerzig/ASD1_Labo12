/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : taquinSolver.h
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 But         : Implémente une classe permettant la résolution d'un jeu de taquin.

 Remarque(s) : Pour une grille résolue, tente de trouver le chemin le plus court
               jusqu'à l'état initial.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ASD1_LABO11_TAQUINSOLVER_H
#define ASD1_LABO11_TAQUINSOLVER_H

#include <vector> // std::vector
#include <array>  // std::array
#include <map>    // std::map
#include <queue>  // std::queue

#include <iostream> // std::cout, std::cin, std::endl


const unsigned DIMENSION  = 3;
const unsigned EMPTY_CELL = 0;

using element = unsigned;
using Grid    = std::array<element, DIMENSION*DIMENSION>;
using Grids   = std::vector<Grid>;
using GridMap = std::map<const Grid, const Grid*>;


enum class PieceToMove{ LEFT = -1, RIGHT = 1, TOP = - (int)DIMENSION, BOTTOM = DIMENSION };

class TaquinSolver
{
public:

   /**
    * @brief Saved state of grid to solve.
    */
   Grid initialGrid;

   Grid solvedGrid;

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
   bool isInit(const Grid& grid);

   /**
    * @brief Fill the gridMap with iterations of initialGrid and so on...
    */
   void generateBFS();

   /**
    * @brief For the given grid, generates all possible next states.
    * @param parentGrid[in] Grid to base next moves on.
    * @param nextGrids[out] Stores the generated grids.
    * @details If a generated grid is already in the gridMap, she is not pushed in queue.
    */
   void generateNextGrids(const Grid* parentGrid, std::queue<const Grid*>& generatedGrids);

   /**
    * @brief Moves the left/right/top/bottom piece next to the empty cell and add it to gridMap.
    * @param grid[in] Grid to edit.
    * @param emptyPos Position of the empty cell.
    * @param pieceToMove Relative position of the cell to move.
    * @param nextGrids[out] Stores the generated grids.
    * @details if the grid is already in the map, it isn't pushed neither in queue ether in queue.
    */
   void moveAndAdd(const Grid* grid, size_t emptyPos, PieceToMove pieceToMove, std::queue<const Grid*>& generatedGrids);

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

   bool isSolved(const Grid &grid);

   void printPath(const Grid& configToStart);

};


#endif //ASD1_LABO11_TAQUINSOLVER_H
