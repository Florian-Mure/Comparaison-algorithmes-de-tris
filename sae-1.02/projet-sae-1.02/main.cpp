#ifdef _WIN32
#include <windows.h>
#endif // Win 32

#include <iostream>
#include <string>
#include <vector>
#include "fonctions.h"
#include "fonction-tri.h"
#include <forward_list>
#include <algorithm>


// Fonctions pour le tri Rapide

// Partitionne le tableau entré en paramètres avec les valeurs minimum et maximum du tableau
int partitionner(std::vector<int> tabTR, int premier, int dernier)
{
    int pivot = tabTR[dernier];    // pivot
    int i = (premier - 1);  // On récupère la plus petite valeur en index

    for (int j = premier; j <= dernier - 1; j++)
    {
        // Si l'élément passé est plus petit ou égal à notre pivot,
        if (tabTR[j] <= pivot)
        {
            i++;
            std::swap(tabTR[i], tabTR[j]); // On swap les valeurs
        }
    }
    std::swap(tabTR[i + 1], tabTR[dernier]);
    return (i + 1);
}

// Tri rapide via récursivité
void tri_rapide(std::vector<int> tabTR, int premier, int dernier)
{
    if (premier < dernier)
    {
        int part = partitionner(tabTR, premier, dernier);

        // Tri des éléments avant et après la partition
        tri_rapide(tabTR, premier, part - 1);
        tri_rapide(tabTR, premier + 1, dernier);
    }
}


int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif // WIN 32
  
      std::vector<tabInit> tabFonctionInitialisation;
    tabFonctionInitialisation.push_back(initTabAleat);
    tabFonctionInitialisation.push_back(initTabPresqueTri);
    tabFonctionInitialisation.push_back(initTabPresqueTriDeb);
    tabFonctionInitialisation.push_back(initTabPresqueTriFin);
    tabFonctionInitialisation.push_back(initTabPresqueTriDebFin);

    std::vector<tabTri> tabFonctionTri;
    tabFonctionTri.push_back(triSelection);
    tabFonctionTri.push_back(triBulles);
    tabFonctionTri.push_back(triBullesOpti);
    tabFonctionTri.push_back(triPeigne);
tabFonctionTri.push_back(triRapide);

// Implémentation de la fonction de tri par sélection (TPS) [tri par sélection = tri par comparaison]
        // Utilisation du pseudo code de wikipédia

    auto tabTPS = initTabAleat(10);
    for (size_t i = 0; i < (tabTPS.size()) - 2; i++)
    {
        int minimum = i;
        for (size_t j = 0; j < (tabTPS.size())-1; j++)
        {
            if (tabTPS[j] < tabTPS[minimum])
                minimum = j;
        }
        if (minimum != i) {
            std::swap(tabTPS[i], tabTPS[minimum]);
        }
    }
    
    // Implémentation de la fonction de tri à bulles (TAB)
        // Utilisation du pseudo code de wikipedia

    auto tabTAB = initTabAleat(10);
    // La boucle se fait sur la valeur maximale de i étant la taille du tableau jusqu'a la valeur 1
    // Car le tri place la plus grande valeur en "passant" les valeurs, a la fin du tableau de valeurs
    for (size_t i = (tabTAB.size()) - 1; i >= 1; i--)
    {
        for (size_t j = 0; j < i-1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j])
                std::swap(tabTAB[j + 1], tabTAB[j]);
        }
    }

    // Implémentation de la fonction de tri a bulles (TAB) optimise
        // Utilisation du pseudo code de wikipédia

    auto tabTABOptimise = initTabAleat(10);
    for (size_t i = (tabTAB.size()) - 1; i >= 1; i--)
    {
        bool tableauTrie = true;
        for (size_t j = 0; j < i - 1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j]) {
                std::swap(tabTAB[j + 1], tabTAB[j]);
                tableauTrie = false;
            }
        }
        // Ici, on verifie si la fonction, en "passant" les valeurs, a procédé à un échange de valeurs.
        // S'il n'a pas échangé de valeurs, cela veut dire que le tableau est déjà trié
        // Donc on arr�te le processus
        if (tableauTrie)
            break;
    }

    // Implémentation de la fonction de tri à peigne (TAP)
        // Utilisation du pseudo code de wikipédia

    auto tabTAP = initTabAleat(10);
    int intervalle = tabTAP.size();
    bool echange = false;
    while (intervalle > 1 || echange == true) {
        intervalle /= 1.3;
        if (intervalle < 1)
            intervalle = 1;
        echange = false;
        for (size_t i = 0; i < tabTAP.size() - intervalle; i++)
        {
            if (tabTAP[i] > tabTAP[i + intervalle]) {
                std::swap(tabTAP[i], tabTAP[i + intervalle]);
                echange = true;
            }
        }
    }

    // Implémentation du tri rapide (TR)
        // Utilisation du pseudo code de Wikipédia

    auto tabTR = initTabAleat(10);
    int n = tabTR.size();
    tri_rapide(tabTR, 0, n - 1);

    return 0;
}