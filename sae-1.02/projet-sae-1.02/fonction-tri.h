#pragma once

#include <vector>
#include <utility>
#include "fonctions.h"

//!\brief Fonction d'impl�mentation du tri par s�lection
std::pair<std::vector<int>, unsigned int> triSelection(tabInit, size_t);

//!\brief Fonction d'implementation du tri � bulles
std::pair<std::vector<int>, unsigned int> triBulles(tabInit, size_t);

//!\brief Fonction d'impl�mentation du tri � bulle optimis�e
std::pair<std::vector<int>, unsigned int> triBullesOpti(tabInit, size_t);

//!\brief Fonction d'impl�mentation du tri � peigne
std::pair<std::vector<int>, unsigned int> triPeigne(tabInit, size_t);

////!\brief Fonction d'impl�mentation du tri rapide
//std::pair<std::vector<int>, unsigned int> triRapide(tabInit, size_t);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabTri = decltype(triSelection)*;