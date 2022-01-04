/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabInit = decltype(initTabAleat)*;

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});

