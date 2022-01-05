#include "fonction-tri.h"

// Implémentation de la fonction de tri par sélection (TPS) [tri par sélection = tri par comparaison]
        // Utilisation du pseudo code de wikipédia
unsigned int triSelection(std::vector<int>& tabTPS)
{
    unsigned int nbComparaison = 0;
    for (size_t i = 0; i < tabTPS.size() - 1; i++)
    {
        unsigned int minimum = i;
        for (size_t j = i + 1; j < tabTPS.size(); j++)
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

    return nbComparaison;
}

// Implémentation de la fonction de tri à bulles (TAB)
    // Utilisation du pseudo code de wikipedia
unsigned int triBulles(std::vector<int>& tabTAB)
{
    unsigned int nbComparaison = 0;
    // La boucle se fait sur la valeur maximale de i etant la taille du tableau jusqu'a la valeur 1
    // Car le tri place la plus grande valeur en "passant" les valeurs, a la fin du tableau de valeurs
    for (size_t i = tabTAB.size(); i >= 1; i--)
    {
        for (size_t j = 0; j < i - 1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j])
                std::swap(tabTAB[j + 1], tabTAB[j]);
            nbComparaison++;
        }
    }

    return nbComparaison;
}

// Implementation de la fonction de tri a bulles (TAB) optimise
    // Utilisation du pseudo code de wikipedia
unsigned int triBullesOpti(std::vector<int>& tabTABOptimise)
{
    unsigned int nbComparaison = 0;
    for (size_t i = tabTABOptimise.size(); i >= 1; i--)
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

    return nbComparaison ;
}

// Implementation de la fonction de tri a peigne (TAP)
    // Utilisation du pseudo code de Wikipedia
unsigned int triPeigne(std::vector<int>& tabTAP)
{
    int intervalle = tabTAP.size();
    bool echange = false;
    unsigned int nbComparaison = 0;
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

    return nbComparaison;
}

// Implementation du tri rapide (TR)
    // Utilisation du pseudo code de Wikipedia

    // Partitionne le tableau entrÃ© en paramÃ¨tres avec les valeurs minimum et maximum du tableau
unsigned int partitionner(std::vector<int>& tabTR, int premier, int dernier, int pivot, unsigned int& nbComparaison)
{
    std::swap(tabTR[pivot], tabTR[dernier]);
    int j = premier;
    for (size_t i = premier; i <= dernier - 1; i++) {
        if (tabTR[i] <= tabTR[dernier]) {
            std::swap(tabTR[i], tabTR[j]);
            j++;
        }
        nbComparaison++;
    }
    std::swap(tabTR[dernier], tabTR[j]);

    return j;
}

int choixPivot(int premier, int dernier)
{
    return static_cast<int>(static_cast<double>(dernier - premier + 1) * std::rand() / (RAND_MAX + 1)) + premier;
}

void triRapide_bis(std::vector<int>& tabTR, int premier, int dernier, unsigned int& nbComparaison)
{
    if (premier < dernier) {
        int pivot = choixPivot(premier, dernier);
        pivot = partitionner(tabTR, premier, dernier, pivot, nbComparaison);
        triRapide_bis(tabTR, premier, pivot - 1, nbComparaison);
        triRapide_bis(tabTR, pivot + 1, dernier, nbComparaison);
    }
    nbComparaison++;
}

unsigned int triRapide(std::vector<int>& tabTR)
{
    unsigned int nbComparaison = 0;
    int n = tabTR.size();
    triRapide_bis(tabTR, 0, n - 1, nbComparaison);

    return nbComparaison;
}
