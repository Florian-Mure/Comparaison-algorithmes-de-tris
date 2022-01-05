#pragma once

#include <vector>
#include <utility>
#include "fonctions.h"

//!\brief Fonction d'implémentation du tri par sélection
unsigned int triSelection(std::vector<int>&);

//!\brief Fonction d'implementation du tri à bulles
unsigned int triBulles(std::vector<int>&);

//!\brief Fonction d'implémentation du tri à bulle optimisée
unsigned int triBullesOpti(std::vector<int>&);

//!\brief Fonction d'implémentation du tri à peigne
unsigned int triPeigne(std::vector<int>&);

//!\brief Fonction d'implémentation du tri rapide pivot aleatoire
unsigned int triRapidePivotAleatoire(std::vector<int>&);

//!\brief Fonction intermediaire du tri rapide avec pivot aléatoire
void triRapideBisPivotAleatoire(std::vector<int>&, int, int, unsigned int&);
unsigned int partitionner(std::vector<int>&, int, int, int, unsigned int&);
int choixPivot(int, int);

//!\brief Fonction d'implémentation du tri rapide pivot arbitraire
unsigned int triRapidePivotArbitraire(std::vector<int>&);
void triRapideBisPivotArbitraire(std::vector<int>&, int, int, unsigned int&);

//!\brief Fonction d'implémentation du tri par insertion
unsigned int triInsertion(std::vector<int>&);

//!\brief Fonction d'implémentation du tri coktail
unsigned int triCoktail(std::vector<int>&);

//!\brief Fonction d'implémentation du tri coktail Optimiser
unsigned int triCoktailOpti(std::vector<int>&);

//!\brief Fonction d'implémentation du tri shell
unsigned int triShell(std::vector<int>&);

//!\brief Fonction d'implémentation du tri par tas
unsigned int triTas(std::vector<int>&);
void tamiser(std::vector<int>&, int, size_t, unsigned int&);

//!\brief Fonction d'implémentation du tri pair-impair
unsigned int triPairImpair(std::vector<int>&);

//!\brief Fonction d'implémentation du tri faire-valoir
unsigned int triFaireValoir(std::vector<int>&);
//!\brief Fonction intermédiaire du tri faire-valoir
void triFaireValoirBis(std::vector<int>&, int, int, unsigned int&);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabTri = decltype(triSelection)*;