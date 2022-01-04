#ifdef _WIN32
#include <windows.h>
#endif // Win 32

#include <iostream>
#include "fonctions.h"

int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif // WIN 32


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
        // Utilisation du pseudo code de wikipédia

    auto tabTAB = initTabAleat(10);
    // La boucle se fait sur la valeur maximale de i étant la taille du tableau jusqu'à la valeur 1
    // Car le tri place la plus grande valeur en "passant" les valeurs, à la fin du tableau de valeurs
    for (size_t i = (tabTAB.size()) - 1; i >= 1; i--)
    {
        for (size_t j = 0; j < i-1; j++)
        {
            if (tabTAB[j + 1] < tabTAB[j])
                std::swap(tabTAB[j + 1], tabTAB[j]);
        }
    }

    // Implémentation de la fonction de tri à bulles (TAB) optimisé
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
        // Ici, on vérifie si la fonction, en "passant" les valeurs, a procédé à un échange de valeurs.
        // S'il n'a pas échangé de valeurs, cela veut dire que le tableau est déjà trié
        // Donc on arrête le processus
        if (tableauTrie)
            break;
    }

    // Implémentation de la fonction de tri à peigne (TAP)
        // Utilisation du pseudo code de Wikipédia

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