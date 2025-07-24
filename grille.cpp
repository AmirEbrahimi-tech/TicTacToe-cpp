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
                case Type::None : cout << "| " << i * 3 + j + 1 <<" "; break;
                case Type::O : cout << "|\033[1;31m O \033[0m"; break;
                case Type::X : cout << "|\033[1;34m X \033[0m"; break;
            }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void Grille::setPiece (int row, int col, Type t) {
    grille[row][col].setType(t);
    grille[row][col].setAge(8);
}

Piece Grille::getPiece (int row, int col) {
    return grille[row][col];
}

int Grille::numPiece (Type t) {
    int counter = 0;
    for ( int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (grille[i][j].getType() == t) counter++;
        }
    }
    return counter;
}

void Grille::setAllPieces () {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (grille[i][j].getAge() == 0) continue;
            else grille[i][j].loseAge();
        }
    }
}

void Grille::input (Type t) {
    int emp;
    cout << "entrez l'emplacement" << endl;
    cin >> emp;
    int row = (emp - 1) / 3;
    int col = (emp - 1) % 3;
    setPiece(row, col, t);
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

// void Grille::setOneRandomPiece () {
//     bool done = false;
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distrib(0, 2);
//     int emptyCells = 0;
//     while (!done) {
//         emptyCells = 0;
//                 if (getPiece(i, j).getType() != Type::None) continue;
//                 switch(distrib(gen)) {
//                     case 1 : setPiece(i, j, Type::O); done = true; break;
//                     case 2 : setPiece(i, j, Type::X); done = true; break;
//                     default : break;
//                 }
//                 if (done) break;
//             }
//             if (done) break;
//         }
//         if (emptyCells == 0) break; // No empty cells, exit to avoid infinite loop
//     }
// }

void Grille::setOneRandomPiece (Type t) {
    if (numPiece(Type::None) == 0) return;
    bool done = false;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribCase (0, 8);
    uniform_int_distribution<> distribType (0, 2);
    while (!done) {
        int tmpCase = distribCase(gen);
        int row = tmpCase / 3;
        int col = tmpCase % 3;
        if (grille[row][col].getType() != Type::None) {
            continue;
        } else {
            // int tmpType = distribType(gen);
            // switch (tmpType) {
            //     case 1 : setPiece(row, col, Type::O) ; done = true; break;
            //     case 2 : setPiece(row, col, Type::X) ; done = true; break;
            //     default : break;
            // }
            setPiece(row, col, t);
            done = true;
        }
    }
}

void Grille::getStatus () {
    for (int i = 0 ; i < 3 ; i++) {
        for (int  j = 0 ; j < 3 ; j++) {
            cout << "case " << i << " - " << j << " : ";
            switch (grille[i][j].getType()) {
                case Type::None : cout << "None" ; break;
                case Type::O : cout << "O" ; break;
                case Type::X : cout << "X" ; break;
            }
            cout << " age : " << grille[i][j].getAge() << endl;
        }
    }
}

Grille testGrilleGagnantLigne () {
    Grille test;
    test.setPiece(0,0,Type::O);
    test.setPiece(0,1,Type::O);
    test.setPiece(0,2,Type::O);
    return test;
}

Grille testGrilleGagnantColonne () {
    Grille test;
    test.setPiece(0,0,Type::O);
    test.setPiece(1,0,Type::O);
    test.setPiece(2,0,Type::O);
    return test;
}

Grille testGrilleGagnantDiagonale () {
    Grille test;
    test.setPiece(0,0,Type::O);
    test.setPiece(1,1,Type::O);
    test.setPiece(2,2,Type::O);
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
                case 0 : test.setPiece(i,j,Type::None); break;
                case 1 : test.setPiece(i,j,Type::O); break;
                case 2 : test.setPiece(i,j,Type::X); break;
            }
        }
    }
    return test;
}