#include "grille.hpp"

using namespace std;
//using Grille = vector<vector<int>>;



Grille::Grille () {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            grille[i][j] = 0;
        }
    }
}

void Grille::affichage () {
    for (int i = 0 ; i < 3 ; i++) {
        cout << "-------------" << endl;
        for (int j = 0 ; j < 3 ; j++) {
            if (grille[i][j] == 0) cout << "|   ";
            else if (grille[i][j] == 1) cout << "| O ";
            else if (grille[i][j] == 2) cout << "| X ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void Grille::setInt (int lig, int col, int val) {
    grille[lig][col] = val;
}

void Grille::input () {
    int lig, col, val;
    cout << "entrez l'emplacement" << endl;
    cin >> lig >> col;
    cout << "entrez un entier entre 1 et 2" << endl;
    cin >> val;
    grille[lig][col] = val;
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
            if (grille[i][j] == 0) {
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
    test.setInt(0,0,1);
    test.setInt(0,1,1);
    test.setInt(0,2,1);
    return test;
}

Grille testGrilleGagnantColonne () {
    Grille test;
    test.setInt(0,0,1);
    test.setInt(1,0,1);
    test.setInt(2,0,1);
    return test;
}

Grille testGrilleGagnantDiagonale () {
    Grille test;
    test.setInt(0,0,1);
    test.setInt(1,1,1);
    test.setInt(2,2,1);
    return test;
}

Grille testGrille () {
    Grille test;
    random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, 2);
    for (int i = 0 ; i < 3 ; i++) {
        for ( int j = 0 ; j < 3 ; j++) {
            test.setInt(i,j,distrib(gen));
        }
    }
    return test;
}