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

    // Partitionne le tableau entrer en parametres avec les valeurs minimum et maximum du tableau
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

// Choix du pivot de facon aleatoire
int choixPivot(int premier, int dernier)
{
    return static_cast<int>(static_cast<double>(dernier - premier + 1) * std::rand() / (RAND_MAX + 1)) + premier;
}

// Fonction intermediaire du tri rapide avec pivot aléatoire
void triRapideBisPivotAleatoire(std::vector<int>& tabTR, int premier, int dernier, unsigned int& nbComparaison)
{
    if (premier < dernier) {
        // Choix du pivot aléatoire
        int pivot = choixPivot(premier, dernier);
        pivot = partitionner(tabTR, premier, dernier, pivot, nbComparaison);
        triRapideBisPivotAleatoire(tabTR, premier, pivot - 1, nbComparaison);
        triRapideBisPivotAleatoire(tabTR, pivot + 1, dernier, nbComparaison);
    }
    nbComparaison++;
}

// Fonction de tri rapide principale avec pivot aléatoire
unsigned int triRapidePivotAleatoire(std::vector<int>& tabTR)
{
    unsigned int nbComparaison = 0;
    int n = tabTR.size();
    triRapideBisPivotAleatoire(tabTR, 0, n - 1, nbComparaison);

    return nbComparaison;
}

// Tri rapide version pivot arbitraire
    // Fonction intermediaire du tri rapide avec pivot arbitraire
void triRapideBisPivotArbitraire(std::vector<int>& tabTR, int premier, int dernier, unsigned int& nbComparaison)
{
    if (premier < dernier) {
        // Choix du pivot arbitraire
        int pivot = dernier;
        pivot = partitionner(tabTR, premier, dernier, pivot, nbComparaison);
        triRapideBisPivotArbitraire(tabTR, premier, pivot - 1, nbComparaison);
        triRapideBisPivotArbitraire(tabTR, pivot + 1, dernier, nbComparaison);
    }
    nbComparaison++;
}

// Fonction de tri rapide principale avec pivot arbritaire
unsigned int triRapidePivotArbitraire(std::vector<int>& tabTR)
{
    unsigned int nbComparaison = 0;
    int n = tabTR.size();
    triRapideBisPivotArbitraire(tabTR, 0, n - 1, nbComparaison);

    return nbComparaison;
}


// Implementation de la fonction de tri par insertion (TPI)
    // Utilisation du pseudo code de wikipedia
unsigned int triInsertion(std::vector<int>& tabTPI)
{
    unsigned int nbComparaison = 0;

    for (size_t i = 1; i < tabTPI.size(); i++) {

        // Memorisation de tabTPI[i] dans x
        int x = tabTPI[i];

        // décalage des éléments tabTPI[0]..tabTPI[i-1] qui sont plus grands que x, en partant de tabTPI[i-1]
        int j = i;
        while (j > 0 && tabTPI[j - 1] > x) {
            tabTPI[j] = tabTPI[j - 1];
            j--;

            nbComparaison++;
        }

        // placement de x dans le "trou" laissé par le décalage
        tabTPI[j] = x;
    }

    return nbComparaison;
}

// Implementation de la fonction de tri coktail (TCK)
    // Utilisation du pseudo code de wikipedia
unsigned int triCoktail(std::vector<int>& tabTCK)
{
    unsigned int nbComparaison = 0;
    bool echanger = true;

    while (echanger) {
        echanger = false;

        for (size_t i = 0; i < tabTCK.size() - 1; i++) {
            
            if (tabTCK[i] > tabTCK[i + 1]) {
                std::swap(tabTCK[i], tabTCK[i + 1]);
                echanger = true;
            }
            nbComparaison++;
        }

        for (size_t j = tabTCK.size() - 2; j > 0; j--) {

            if (tabTCK[j] > tabTCK[j + 1]) {
                std::swap(tabTCK[j], tabTCK[j + 1]);
                echanger = true;
            }
            nbComparaison++;
        }
    }

    return nbComparaison;
}

// Implementation de la fonction de tri coktail (TCK) Optimiser
    // Utilisation du pseudo code de wikipedia
unsigned int triCoktailOpti(std::vector<int>& tabTCKOpti)
{
    unsigned int nbComparaison = 0;
    bool echanger = true;
    int debut = 0;
    int fin = tabTCKOpti.size() - 2;

    while (echanger) {
        echanger = false;

        for (size_t i = debut; i <= fin; i++) {

            if (tabTCKOpti[i] > tabTCKOpti[i + 1]) {
                std::swap(tabTCKOpti[i], tabTCKOpti[i + 1]);
                echanger = true;
            }
            nbComparaison++;
        }

        fin--;

        for (size_t j = fin; j > debut; j--) {

            if (tabTCKOpti[j] > tabTCKOpti[j + 1]) {
                std::swap(tabTCKOpti[j], tabTCKOpti[j + 1]);
                echanger = true;
            }
            nbComparaison++;
        }

        debut++;
    }

    return nbComparaison;
}

// Implementation de la fonction de tri Shell (TSH)
    // Utilisation du pseudo code de wikipedia
unsigned int triShell(std::vector<int>& tabTSH)
{
    unsigned int nbComparaison = 0;
    int n = tabTSH.size();
    std::vector<int> espacements = { 701, 301, 132, 57, 23, 10, 4, 1 };

    for (auto e : espacements) {

        for (size_t i = e; i < n; i++) {
            int temp = tabTSH[i];
            int j = i;

            while (j >= e && tabTSH[j - e] > temp) {
                tabTSH[j] = tabTSH[j - e];
                j -= e;
            }
            nbComparaison++;

            tabTSH[j] = temp;
        }
    }

    return nbComparaison;
}

// Implementation de la fonction de tri par tas (TTA)
    // Utilisation du pseudo code de wikipedia --> pas reussi
unsigned int triTas(std::vector<int>& tabTTA)
{
    unsigned int nbComparaison = 0;
    size_t n = tabTTA.size();

    for (size_t i = n/2 - 1; i > 0; i--) {
        tamiser(tabTTA, i, n, nbComparaison);
    }

    for (size_t i = n - 1; i > 0; i--) {
        std::swap(tabTTA[0], tabTTA[i]);
        tamiser(tabTTA, 0, i, nbComparaison);
    }

    return nbComparaison;
}

void tamiser(std::vector<int>& tabTTA, int noeud, size_t n, unsigned int& nbComparaison)
{
    int k = noeud;
    int j = 2 * k;

    while (j <= n) {
        nbComparaison++;

        if (j < n && tabTTA[j] < tabTTA[j + 1]) {
            j++;
        }
        nbComparaison++;

        if (tabTTA[k] < tabTTA[j]) {
            std::swap(tabTTA[k], tabTTA[j]);
            k = j;
            j = 2/k;
        }
        else {
            j = n + 1;
        }
        nbComparaison++;
    }
}

// Implementation de la fonction de tri pair-impair (TPI)
    // Utilisation du pseudo code de wikipedia
unsigned int triPairImpair(std::vector<int>& tabTPI)
{
    unsigned int nbComparaison = 0;
    bool trier = false;

    while (!trier) {
        trier = true;

        // Comparaisons impaires-paires 
        for (size_t i = 0; i < tabTPI.size() - 1; i += 2) {

            if (tabTPI[i] > tabTPI[i + 1]) {
                std::swap(tabTPI[i], tabTPI[i + 1]);
                trier = false;
            }
            nbComparaison++;
        }

        //comparaisons paires-impaires
        for (size_t j = 1; j < tabTPI.size() - 1; j += 2) {

            if (tabTPI[j] > tabTPI[j + 1]) {
                std::swap(tabTPI[j], tabTPI[j + 1]);
                trier = false;
            }
            nbComparaison++;
        }
    }

    return nbComparaison;
}

// Implementation de la fonction de tri faire-valoir (TFV)
    // Utilisation du pseudo code de wikipedia
unsigned int triFaireValoir(std::vector<int>& tabTFV)
{
    unsigned int nbComparaison = 0;
    int n = tabTFV.size();
    triFaireValoirBis(tabTFV, 0, n - 1, nbComparaison);

    return nbComparaison;
}

// Fonction intermédiaire du tri faire-valoir
void triFaireValoirBis(std::vector<int>& tabTFV, int debut, int fin, unsigned int& nbComparaison)
{
    if (tabTFV[debut] > tabTFV[fin]) {
        std::swap(tabTFV[debut], tabTFV[fin]);
    }
    nbComparaison++;

    if ((fin - debut + 1) > 2) {
        int t = (fin - debut + 1) / 3;
        triFaireValoirBis(tabTFV, debut, fin - t, nbComparaison);
        triFaireValoirBis(tabTFV, debut + t, fin, nbComparaison);
        triFaireValoirBis(tabTFV, debut, fin - t, nbComparaison);
    }
    nbComparaison++;
}