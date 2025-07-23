#include "grille.hpp"

using namespace std;
//using Grille = vector<vector<int>>;



Grille::Grille () {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            grille[i][j] = Piece();
        }
    }
}

void Grille::affichage () {
    for (int i = 0 ; i < 3 ; i++) {
        cout << "-------------" << endl;
        for (int j = 0 ; j < 3 ; j++) {
            switch (grille[i][j].getType()) {
                case Type::None : cout << "|   "; break;
                case Type::O : cout << "| O "; break;
                case Type::X : cout << "| X "; break;
            }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void Grille::setInt (int lig, int col, Type t) {
    grille[lig][col].setType(t);
}

void Grille::input () {
    int lig, col, val;
    cout << "entrez l'emplacement" << endl;
    cin >> lig >> col;
    cout << "entrez un entier entre 1 et 2" << endl;
    cin >> val;
    switch (val) {
        case 0 : grille[lig][col].setType(Type::None); break;
        case 1 : grille[lig][col].setType(Type::O); break;
        case 2 : grille[lig][col].setType(Type::X); break;
    }
}

bool Grille::partieFinie () {
    // digonale
    if (grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2]) return true;
    else if (grille[2][0] == grille[1][1] && grille[1][1] == grille[0][2]) return true;
    // ligne et colonne
    int ind = 0;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (ind > i || ind > j) continue;
            if (grille[i][j].getType() == Type::None) {
                ind++;
                continue;
            }
            if (grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2]) return true;
            else if (grille[0][j] == grille[1][j] && grille[1][j] == grille[2][j]) return true;
        }
    }
    return false;
}

Grille testGrilleGagnantLigne () {
    Grille test;
    test.setInt(0,0,Type::O);
    test.setInt(0,1,Type::O);
    test.setInt(0,2,Type::O);
    return test;
}

Grille testGrilleGagnantColonne () {
    Grille test;
    test.setInt(0,0,Type::O);
    test.setInt(1,0,Type::O);
    test.setInt(2,0,Type::O);
    return test;
}

Grille testGrilleGagnantDiagonale () {
    Grille test;
    test.setInt(0,0,Type::O);
    test.setInt(1,1,Type::O);
    test.setInt(2,2,Type::O);
    return test;
}

Grille testGrille () {
    Grille test;
    random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, 2);
    for (int i = 0 ; i < 3 ; i++) {
        for ( int j = 0 ; j < 3 ; j++) {
            switch(distrib(gen)) {
                case 0 : test.setInt(i,j,Type::None); break;
                case 1 : test.setInt(i,j,Type::O); break;
                case 2 : test.setInt(i,j,Type::X); break;
            }
        }
    }
    return test;
}