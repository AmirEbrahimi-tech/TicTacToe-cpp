#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <random>
#include <iostream>
#include "piece.hpp"

using namespace std;

class Grille {

    public :

        Grille ();
        void affichage ();
        void setPiece (int row, int col, Type t);
        Piece getPiece (int row, int col);
        int numPiece (Type t);
        void setAllPieces ();
        void input (Type t);
        bool partieFinie ();
        void setOneRandomPiece (Type t);
        void getStatus ();

    private :

        // vector<vector<int>> grille;
        Piece grille[3][3];
};

Grille testGrilleGagnantLigne ();

Grille testGrilleGagnantColonne ();

Grille testGrilleGagnantDiagonale ();

Grille testGrille ();


#endif