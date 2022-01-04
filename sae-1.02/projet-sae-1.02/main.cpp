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

// Exo 3
    // 3.3 : tri rapide


    return 0;
}