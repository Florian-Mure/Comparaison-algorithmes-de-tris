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


// Fonctions pour le tri Rapide

// Partitionne le tableau entrÃ© en paramÃ¨tres avec les valeurs minimum et maximum du tableau
int partitionner(std::vector<int> tabTR, int premier, int dernier)
{
    int pivot = tabTR[dernier];    // pivot
    int i = (premier - 1);  // On rÃ©cupÃ¨re la plus petite valeur en index

    for (int j = premier; j <= dernier - 1; j++)
    {
        // Si l'Ã©lÃ©ment passÃ© est plus petit ou Ã©gal Ã  notre pivot,
        if (tabTR[j] <= pivot)
        {
            i++;
            std::swap(tabTR[i], tabTR[j]); // On swap les valeurs
        }
    }
    std::swap(tabTR[i + 1], tabTR[dernier]);
    return (i + 1);
}

// Tri rapide via rÃ©cursivitÃ©
void tri_rapide(std::vector<int> tabTR, int premier, int dernier)
{
    if (premier < dernier)
    {
        int part = partitionner(tabTR, premier, dernier);

        // Tri des Ã©lÃ©ments avant et aprÃ¨s la partition
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
    //tabFonctionTri.push_back({ triRapide, "triRapide" });


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
            << ";PresqueTriFin " << tri.second << ";";

    }
    out << "\n";


    // Affichage pour chaque tri, pour chaque initialisation de tableau en fonction de la taille n le nombre de comparaison
    for (size_t n = 8; n < 15; n++) {
        out << n << ";";
        for (auto tri : tabFonctionTri) {
            std::cout << "- Fonction de tri : \x1B[1;31m" << tri.second << "\x1B[0m\n";
            for (auto init : tabFonctionInitialisation) {
                out << tri.first(init.first, n).second << ";";
                std::cout << "Fonction d'initialisation : \x1B[1;32m" << init.second << "\x1B[0m\n";
                std::cout << "Tableau de taille \x1B[1;33m" << n << "\x1B[0m, nombre de comparaison est de \x1B[1;34m" << tri.first(init.first, n).second << "\x1B[0m\n";
            }
        }
        out << "\n";

    }

    // ImplÃ©mentation du tri rapide (TR)
        // Utilisation du pseudo code de WikipÃ©dia

    auto tabTR = initTabAleat(10);
    int n = tabTR.size();
    tri_rapide(tabTR, 0, n - 1);

    return 0;
}