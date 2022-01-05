#pragma once

#include <vector>
#include <utility>
#include "fonctions.h"

//!\brief Fonction d'impl�mentation du tri par s�lection
unsigned int triSelection(std::vector<int>&);

//!\brief Fonction d'implementation du tri � bulles
unsigned int triBulles(std::vector<int>&);

//!\brief Fonction d'impl�mentation du tri � bulle optimis�e
unsigned int triBullesOpti(std::vector<int>&);

//!\brief Fonction d'impl�mentation du tri � peigne
unsigned int triPeigne(std::vector<int>&);

////!\brief Fonction d'impl�mentation du tri rapide
unsigned int triRapide(std::vector<int>&);
void triRapide_bis(std::vector<int>&, int, int, unsigned int&);
unsigned int partitionner(std::vector<int>&, int, int, int, unsigned int&);
int choixPivot(int, int);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabTri = decltype(triSelection)*;