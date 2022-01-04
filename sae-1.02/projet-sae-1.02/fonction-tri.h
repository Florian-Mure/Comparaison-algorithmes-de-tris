#pragma once

#include <vector>
#include <utility>

//!\brief Fonction d'implémentation du tri par sélection
std::pair<std::vector<int>, unsigned int> triSelection(std::vector<int>);

//!\brief Fonction d'implementation du tri à bulles
std::pair<std::vector<int>, unsigned int> triBulles(std::vector<int>);

//!\brief Fonction d'implémentation du tri à bulle optimisée
std::pair<std::vector<int>, unsigned int> triBullesOpti(std::vector<int>);

//!\brief Fonction d'implémentation du tri à peigne
std::pair<std::vector<int>, unsigned int> triPeigne(std::vector<int>);

//!\brief Fonction d'implémentation du tri rapide
std::pair<std::vector<int>, unsigned int> triRapide(std::vector<int>);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabTri = decltype(triSelection)*;