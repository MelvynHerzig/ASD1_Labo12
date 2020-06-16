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
      solvedGrid[i] = (unsigned short)i;
   }
}

void TaquinSolver::solveConfig()
{
   if(generateBFSUntilSolved())
   {
      printPath();
   }
   else
   {
      std::cout << "Solution insoluble." << std::endl;
   }
}

bool TaquinSolver::isInit(const Grid &grid) const
{
   return grid == initialGrid;
}

bool TaquinSolver::isSolved(const Grid &grid) const
{
   return grid == solvedGrid;
}

bool TaquinSolver::generateBFSUntilSolved()
{
   // Insertion de la grille initiale.
   auto insertResult = gridMap.insert(std::make_pair(solvedGrid, &solvedGrid));
   generatedGrids.push(&insertResult.first->first);

   while(not generatedGrids.empty())
   {
      generateNextGrids(generatedGrids.front());

      if(isInit(*generatedGrids.front()))
      {
         return true;
      }

      generatedGrids.pop();
   }

   return false;
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

   tryInsertion(generatedGrid, grid);
}

void TaquinSolver::tryInsertion(const Grid& grid, const Grid* parent)
{
   if(gridMap.find(grid) == gridMap.end())
   {
      auto insertResult = gridMap.insert(std::make_pair(grid, parent));
      generatedGrids.push(&insertResult.first->first);
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

void TaquinSolver::printPath() const
{
   Grid kid = initialGrid;
   const Grid* parent = getParent(kid);

   while(not isSolved(kid))
   {
      if(parent == nullptr)
      {
         std::cout << "Erreur lors de la resolution" << std::endl;
         return;
      }

      std::cout << (size_t) std::distance(parent->begin(), std::find(parent->begin(), parent->end(), EMPTY_CELL)) << " ";

      kid = *parent;
      parent = getParent(kid);
   }
}

const Grid* TaquinSolver::getParent(const Grid& grid) const
{
   GridMap::const_iterator it = gridMap.find(grid);

   if(it != gridMap.end())
   {
      return it->second;
   }
   else
   {
      return nullptr;
   }
}