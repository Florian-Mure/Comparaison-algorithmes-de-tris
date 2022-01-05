#ifdef _WIN32
#include <windows.h>
#endif // Win 32

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "fonctions.h"
#include "fonction-tri.h"
#include <forward_list>
#include <algorithm>


int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif // WIN 32

    std::srand(std::time(0));
  
    // Creation d'un tableau de fonction d'initialisation de suites de chiffres a trier
    std::vector<std::pair<tabInit, std::string>> tabFonctionInitialisation;
    tabFonctionInitialisation.push_back({ initTabAleat, "initTabAleat"});
    tabFonctionInitialisation.push_back({ initTabPresqueTri, "initTabPresqueTri"});
    tabFonctionInitialisation.push_back({ initTabPresqueTriDeb, "initTabPresqueTriDeb"});
    tabFonctionInitialisation.push_back({ initTabPresqueTriFin, "initTabPresqueTriFin"});
    tabFonctionInitialisation.push_back({ initTabPresqueTriDebFin, "initTabPresqueTriDebFin"});

    // Creation d'un tableau de fonction de tri de suites de chiffres
    std::vector<std::pair<tabTri, std::string>> tabFonctionTri;
    tabFonctionTri.push_back({ triSelection, "triSelection"});
    tabFonctionTri.push_back({ triBulles, "triBulles" });
    tabFonctionTri.push_back({ triBullesOpti, "triBullesOpti" });
    tabFonctionTri.push_back({ triPeigne, "triPeigne"});
    tabFonctionTri.push_back({ triRapide, "triRapide" });


    // Ouverture du fichier outputCSV
    std::ofstream out("outputCSV.csv");
    if (!out.is_open())
        std::cerr << "Problème d'ouverture du fichier \"outputCSV.csv\".\n";

    // Ajout de l'entete dans le fichier de sortie csv
    out << "N;";
    for (auto tri : tabFonctionTri) {
        out << "Aleat " << tri.second
            << ";PresqueTri " << tri.second
            << ";PresqueTriDeb " << tri.second
            << ";PresqueTriDebFin " << tri.second
            << ";PresqueTriFin " << tri.second << ";;;";

    }
    out << "\n";

    // Affichage pour chaque tri, pour chaque initialisation de tableau en fonction de la taille n le nombre de comparaison
    for (size_t n = 25; n < 1501; n++) {
        out << n << ";";
        for (auto tri : tabFonctionTri) {
            std::cout << "- Fonction de tri : \x1B[1;31m" << tri.second << "\x1B[0m\n";
            for (auto init : tabFonctionInitialisation) {
                std::vector<int> tabToTRI = init.first(n);
                auto nbComparaison = tri.first(tabToTRI);
                out << nbComparaison << ";";
                std::cout << "Fonction d'initialisation : \x1B[1;32m" << init.second << "\x1B[0m\n";
                std::cout << "Tableau de taille \x1B[1;33m" << n << "\x1B[0m, nombre de comparaison est de \x1B[1;34m" << nbComparaison << "\x1B[0m\n";
            }
            out << ";;";
        }
        out << "\n";
    }

    return 0;
}