#ifdef _WIN32
#include <windows.h>
#endif // Win 32

#include <iostream>
#include <string>
#include "fonctions.h"
#include "fonction-tri.h"

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
        for (size_t j = 0; j < (tabTPS.size()) - 1; j++)
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
    // La boucle se fait sur la valeur maximale de i etant la taille du tableau jusqu'a la valeur 1
    // Car le tri place la plus grande valeur en "passant" les valeurs, a la fin du tableau de valeurs
    for (size_t i = (tabTAB.size()) - 1; i >= 1; i--)
    {
        for (size_t j = 0; j < i-1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j])
                std::swap(tabTAB[j + 1], tabTAB[j]);
        }
    }

    // Impl�mentation de la fonction de tri a bulles (TAB) optimise
        // Utilisation du pseudo code de wikip�dia

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
        // Ici, on verifie si la fonction, en "passant" les valeurs, a proc�d� � un �change de valeurs.
        // S'il n'a pas �chang� de valeurs, cela veut dire que le tableau est d�j� tri�
        // Donc on arr�te le processus
        if (tableauTrie)
            break;
    }

    // Impl�mentation de la fonction de tri � peigne (TAP)
        // Utilisation du pseudo code de Wikip�dia

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


    return 0;
}