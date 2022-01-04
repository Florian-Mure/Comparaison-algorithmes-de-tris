#include "fonction-tri.h"

// Implémentation de la fonction de tri par sélection (TPS) [tri par sélection = tri par comparaison]
        // Utilisation du pseudo code de wikipédia
std::pair<std::vector<int>, unsigned int> triSelection(tabInit fonction, size_t n)
{
    auto tabTPS = fonction(n);
    unsigned int nbComparaison = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        int minimum = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (tabTPS[j] < tabTPS[minimum])
                minimum = j;
            nbComparaison++;
        }
        if (minimum != i) {
            std::swap(tabTPS[i], tabTPS[minimum]);
        }
        nbComparaison++;
    }

    return { tabTPS, nbComparaison };
}

// Implémentation de la fonction de tri à bulles (TAB)
    // Utilisation du pseudo code de wikipedia
std::pair<std::vector<int>, unsigned int> triBulles(tabInit fonction, size_t n)
{
    auto tabTAB = fonction(n);
    int nbComparaison = 0;
    // La boucle se fait sur la valeur maximale de i etant la taille du tableau jusqu'a la valeur 1
    // Car le tri place la plus grande valeur en "passant" les valeurs, a la fin du tableau de valeurs
    for (size_t i = n; i >= 1; i--)
    {
        for (size_t j = 0; j < i - 1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j])
                std::swap(tabTAB[j + 1], tabTAB[j]);
            nbComparaison++;
        }
    }

    return { tabTAB, nbComparaison };
}

// Implementation de la fonction de tri a bulles (TAB) optimise
    // Utilisation du pseudo code de wikipedia
std::pair<std::vector<int>, unsigned int> triBullesOpti(tabInit fonction, size_t n)
{
    auto tabTABOptimise = fonction(n);
    int nbComparaison = 0;
    for (size_t i = n; i >= 1; i--)
    {
        bool tableauTrie = true;
        for (size_t j = 0; j < i - 1; j++)
        {
            if (tabTABOptimise[j + 1] < tabTABOptimise[j]) {
                std::swap(tabTABOptimise[j + 1], tabTABOptimise[j]);
                tableauTrie = false;
            }
            nbComparaison++;
        }
        // Ici, on verifie si la fonction, en "passant" les valeurs, a procede a un echange de valeurs.
        // S'il n'a pas echange de valeurs, cela veut dire que le tableau est deja trie
        // Donc on arrete le processus
        if (tableauTrie)
            break;
    }

    return { tabTABOptimise, nbComparaison };
}

// Implementation de la fonction de tri a peigne (TAP)
    // Utilisation du pseudo code de Wikipedia
std::pair<std::vector<int>, unsigned int> triPeigne(tabInit fonction, size_t n)
{
    auto tabTAP = fonction(n);
    int intervalle = tabTAP.size();
    bool echange = false;
    int nbComparaison = 0;
    while (intervalle > 1 || echange == true) {
        intervalle /= 1.3;
        if (intervalle < 1)
            intervalle = 1;
        nbComparaison++;
        echange = false;
        for (size_t i = 0; i < tabTAP.size() - intervalle; i++)
        {
            if (tabTAP[i] > tabTAP[i + intervalle]) {
                std::swap(tabTAP[i], tabTAP[i + intervalle]);
                echange = true;
            }
            nbComparaison++;
        }
    }

    return { tabTAP, nbComparaison };
}

//std::pair<std::vector<int>, unsigned int> triRapide(std::vector<int>)
//{
//
//}