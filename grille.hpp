#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <random>
#include <iostream>

using namespace std;

class Grille {

    public :

        Grille ();
        void affichage ();
        void setInt (int lig, int col, int val);
        void input ();
        bool partieFinie ();

    private :

        // vector<vector<int>> grille;
        int grille[3][3];
};

Grille testGrilleGagnantLigne ();

Grille testGrilleGagnantColonne ();

Grille testGrilleGagnantDiagonale ();

Grille testGrille ();


#endif