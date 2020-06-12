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
#include <algorithm> // std::find, std::distance, std::swap
#include <iostream>  // std::cout, std::endl;

#include "taquinSolver.h"

void TaquinSolver::initConfig()
{
   for (size_t i = 0; i < DIMENSION * DIMENSION; ++i)
   {
      std::cin >> initialGrid[i];
      solvedGrid[i] = i;
   }
}

void TaquinSolver::solveConfig()
{
   generateBFS();
}

bool TaquinSolver::isInit(const Grid &grid)
{
   return grid == initialGrid;
}

bool TaquinSolver::isSolved(const Grid &grid)
{
   return grid == solvedGrid;
}

void TaquinSolver::generateBFS()
{
   // Inserting initial grid
   auto insertResult = gridMap.insert(std::make_pair(solvedGrid, &solvedGrid));
   generatedGrids.push(&insertResult.first->first);

   while(not generatedGrids.empty())
   {
      generateNextGrids(generatedGrids.front());

      if(isInit(*generatedGrids.front()))
      {
         printPath(*generatedGrids.front());
         return;
      }

      generatedGrids.pop();
   }
}

void TaquinSolver::generateNextGrids(const Grid* parentGrid)
{
   size_t position = (size_t)std::distance(parentGrid->begin(), std::find(parentGrid->begin(), parentGrid->end(), EMPTY_CELL));

   if(not isFirstRow(position))
   {
      moveAndAdd(parentGrid, position, PieceToMove::TOP);
   }

   if(not isLastRow(position))
   {
      moveAndAdd(parentGrid, position, PieceToMove::BOTTOM);
   }

   if(not isFirstCol(position))
   {
      moveAndAdd(parentGrid, position, PieceToMove::LEFT);
   }

   if(not isLastCol(position))
   {
      moveAndAdd(parentGrid, position, PieceToMove::RIGHT);
   }
}

void TaquinSolver::moveAndAdd(const Grid* grid, size_t emptyPos, PieceToMove pieceToMove)
{
   Grid generatedGrid = *grid;
   std::swap(generatedGrid[emptyPos], generatedGrid[emptyPos + (size_t)pieceToMove]);

   // If it is the first generation of the grid
   if(gridMap.find(generatedGrid) == gridMap.end())
   {
      auto insertResult = gridMap.insert(std::make_pair(generatedGrid, grid));
      generatedGrids.push(&insertResult.first->first);
   }
}

void TaquinSolver::printPath(const Grid& configToStart)
{
   Grid kid    = configToStart;
   Grid parent = *gridMap.find(configToStart)->second;

   while(not isSolved(kid))
   {
      std::cout << (size_t) std::distance(parent.begin(), std::find(parent.begin(), parent.end(), EMPTY_CELL)) << " ";

      kid = parent;
      parent = *gridMap.find(kid)->second;
   }
}

bool TaquinSolver::isFirstRow(size_t position)
{
   return position < DIMENSION;
}

bool TaquinSolver::isLastRow(size_t position)
{
   return position >= DIMENSION * (DIMENSION-1) && position < DIMENSION * DIMENSION;
}

bool TaquinSolver::isFirstCol(size_t position)
{
   return position % DIMENSION == 0;
}

bool TaquinSolver::isLastCol(size_t position)
{
   return position % DIMENSION == DIMENSION - 1;
}
