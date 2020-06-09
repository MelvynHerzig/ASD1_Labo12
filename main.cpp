/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : main.cpp
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 But         : Utiliser la classe TaquinSolver pour trouver une solution à un jeu
               de taquin dont l'état initial est donné.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>  // EXIT_SUCCESS

#include "taquinSolver.h" // TaquinSolver

int main ()
{
   // Initialisation du résolveur.
   TaquinSolver taquinSolver = {};

   // Réception de la configuration initiale.
   std::cout << "Entrez la configuration initiale: " << std::endl;
   taquinSolver.initConfig();

   // Résolution et affichage de la solution
   taquinSolver.solveConfig();

   return EXIT_SUCCESS;
}
