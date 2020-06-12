/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : taquinSolver.h
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 But         : Implémente une classe permettant la résolution d'un jeu de taquin.

 Remarque(s) : Pour une grille initiale, tente de trouver le chemin le plus court
               jusqu'à l'état résolu.

               Ne fonctionne pas avec une grille 4*4 par manque
               d'optimisation mémoire.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ASD1_LABO11_TAQUINSOLVER_H
#define ASD1_LABO11_TAQUINSOLVER_H

#include <array>  // std::array
#include <map>    // std::map
#include <queue>  // std::queue

#include <iostream> // std::cout, std::cin, std::endl


const unsigned DIMENSION  = 3;
const unsigned EMPTY_CELL = 0;

using element = unsigned;
using Grid    = std::array<element, DIMENSION*DIMENSION>;
using GridMap = std::map<const Grid, const Grid*>; //Enfant et parent

// Par rapport à la pièce 0, perment de déterminer le numéro des pièces adjacentes.
enum class PieceToMove{ LEFT = -1, RIGHT = 1, TOP = - (int)DIMENSION, BOTTOM = DIMENSION };

class TaquinSolver
{
public:

   /**
    * @brief Construit la grille initiale et la grille finale.
    */
   void initConfig();

   /**
    * @brief Génère horizontalement les grilles et affiche les déplacements à effectuer.
    */
   void solveConfig();

private:

   /**
  * @brief Grille avec l'état mélangé du plateau.
  */
   Grid initialGrid;

   /**
   * @brief Grille avec l'état arrangé du plateau.
   */
   Grid solvedGrid;

   /**
    * @brief Map contenant les différentes grilles générées avec leurs parents.
    */
   GridMap gridMap;

   /**
    * @brief Contient les grilles générées qui seront à traiter.
    */
   std::queue<const Grid*> generatedGrids;

   /**
    * @biref Pour une grille, compare si égale avec initialGrid.
    * @param grid Grille à comparer
    * @return Vrai si égales sinon faux.
    */
   bool isInit(const Grid& grid);

   /**
    * @biref Pour une grille, compare si égale avec solvedGrid.
    * @param grid Grille à comparer
    * @return Vrai si égales sinon faux.
    */
   bool isSolved(const Grid &grid);

   /**
    * @brief Génère horizontalement les enfant de gridMap et les y ajoute si pas encore présents
    */
   void generateBFSUntilSolved();

   /**
    * @brief Pour une grille données, génère les prochains états possibles
    * @param parentGrid Grille à générer les prochains états
    */
   void generateNextGrids(const Grid* parentGrid);

   /**
    * @brief Pour la grille données, effectue le déplacement demandé.
    * @param grid Grille a déplacer
    * @param emptyPos Position de la case vide.
    * @param pieceToMove Pièce a déplacer.
    */
   void moveAndAdd(const Grid* grid, size_t emptyPos, PieceToMove pieceToMove);

   /**
    * @brief Tente d'ajouter grid dans gridMap si pas encore présente.
    * @param grid Grille à tenter d'ajouter.
    * @param parent Pointeur vers la grille parent.
    */
   void tryInsertion(const Grid& grid, const Grid* parent);

   /**
    * @biref Détermine si l'indice de la case vide se trouve sur la première ligne.
    * @param position Position de la case vide.
    * @return Vrai si sur la première ligne
    */
   static bool isFirstRow(size_t position);

    /**
    * @biref Détermine si l'indice de la case vide se trouve sur la dernière ligne.
    * @param position Position de la case vide.
    * @return Vrai si sur la dernière ligne
    */
   static bool isLastRow(size_t position);

    /**
    * @biref Détermine si l'indice de la case vide se trouve sur la première colonne.
    * @param position Position de la case vide.
    * @return Vrai si sur la première colonne
    */
   static bool isFirstCol(size_t position);

    /**
    * @biref Détermine si l'indice de la case vide se trouve sur la denière colonne.
    * @param position Position de la case vide.
    * @return Vrai si sur la dernière colonne.
    */
   static bool isLastCol(size_t position);

   /**
    * @brief Depuis une config, affiche les déplacement à effectuer jusqu'a atteindre solvedGrid
    * @param configToStart grille depuis laquelle afficher les déplacement
    */
   void printPath();

   /**
    * @brief pour une grille donnée, récupre sont parent dans gridMap.
    * @param grid Grille à trouver le parent.
    * @return Pointeur sur la grille parent si succès sinon nullptr;
    */
   const Grid* getParent(const Grid& grid);

};

#endif //ASD1_LABO11_TAQUINSOLVER_H
