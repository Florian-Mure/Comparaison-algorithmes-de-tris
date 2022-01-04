#pragma once

#include <vector>
#include <utility>

//!\brief Fonction d'impl�mentation du tri par s�lection
std::pair<std::vector<int>, unsigned int> triSelection(std::vector<int>);

//!\brief Fonction d'implementation du tri � bulles
std::pair<std::vector<int>, unsigned int> triBulles(std::vector<int>);

//!\brief Fonction d'impl�mentation du tri � bulle optimis�e
std::pair<std::vector<int>, unsigned int> triBullesOpti(std::vector<int>);

//!\brief Fonction d'impl�mentation du tri � peigne
std::pair<std::vector<int>, unsigned int> triPeigne(std::vector<int>);

//!\brief Fonction d'impl�mentation du tri rapide
std::pair<std::vector<int>, unsigned int> triRapide(std::vector<int>);

//!\brief Declaration du type des fonctions d'initialisation de tableau dans la variable GenerateTab
using tabTri = decltype(triSelection)*;