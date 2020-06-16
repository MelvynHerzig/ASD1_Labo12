/*
 -----------------------------------------------------------------------------------
 Laboratoire : 12
 Fichier     : main.cpp
 Auteur(s)   : Melvyn Herzig
 Date        : 08.06.2020

 But         : Utiliser la classe TaquinSolver pour trouver une solution à un jeu
               de taquin dont l'état initial est donné.

 Remarque(s) :
                  Taille mémoire:
               Nombre de grilles possibles = 9! = 362 880 = n
               sizeof(unsigned short) = 2 Bytes = E
               sizeof(void*) = 4 Bytes = P
               std:array 3*3 = 9 * E = 18 Byte = G

               Taille Queue: au plus O(2 * n + 3) * P
               Taille Map: O(n) * ( 4 * P + G)

               Donc pour la classe:
               2 * G + O(2 * n + 3) * P + O(n) * ( 4 * P + G )

                  Temps de calcul:
               O(n*log(n))

                  Estimation de la taille possible:
               Si nous voulons stocker toutes les générations d'un grille:
               Par simplification on estime uniquement la taille de la map pour tout n 3*3:
               362880 * 34B = 0.01 GB

               Si on estime avec du 4*4:
               taille grille = 16 * E = 32 Bytes
               16! * (16 + 32) = 1'004'293 GB

               Nous pouvons donc facilement dire qu'il est possible de résoudre, au
               maximum des grilles 3*3 avec l'implémentation actuelle


 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout

#include "taquinSolver.h" // TaquinSolver

using namespace std;
int main ()
{
   // Initialisation du résolveur.
   TaquinSolver taquinSolver;

   // Réception de la configuration initiale.
   std::cout << "Entrez la configuration initiale: " << std::endl;
   taquinSolver.initConfig();

   // Résolution et affichage de la solution
   std::cout << "Solution:" << std::endl;
   taquinSolver.solveConfig();

   return EXIT_SUCCESS;
}
