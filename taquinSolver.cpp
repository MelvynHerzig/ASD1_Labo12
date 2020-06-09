/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : taquinSolver.cpp
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <queue>     // std::queue
#include <algorithm> // std::find, std::distance

#include "taquinSolver.h"

TaquinSolver::TaquinSolver()
{}

void TaquinSolver::initConfig()
{
   for (size_t i = 0; i < DIMENSION * DIMENSION; ++i)
   {
      std::cin >> initialGrid[i];
   }

   gridMap.insert(std::make_pair(initialGrid, &initialGrid));
}

void TaquinSolver::solveConfig()
{

}

bool TaquinSolver::isSolved(const Grid &grid)
{
   for(size_t i = 0; i < DIMENSION * DIMENSION; ++i)
   {
      if(grid[i] != i) return false;
   }

   return true;
}

void TaquinSolver::generateBFS()
{
   std::queue<Grid> generatedGrid; // Will contains generated grid to add (or not) to gridMap
   generatedGrid.push(initialGrid);

  Grids nextGrid; // Receive the next state from current grid.

   while(not generatedGrid.empty())
   {

   }

}

Grids TaquinSolver::generateNextState(const Grid& grid) const
{
  size_t position = (size_t)std::distance(grid.begin(), std::find(grid.begin(), grid.end(), EMPTY_CELL));


}

static bool isFirstRow(size_t position)
{
   return position < DIMENSION;
}

static bool isLastRow(size_t position)
{
   return position >= DIMENSION * (DIMENSION-1) && position < DIMENSION * DIMENSION;
}

static bool isFirstCol(size_t position)
{
   return position % DIMENSION == 0;
}

static bool isLastCol(size_t position)
{
   return position % DIMENSION == DIMENSION - 1;
}
