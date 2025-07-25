#include "grid.hpp"

using namespace std;
//using Grid = vector<vector<int>>;

Grid::Grid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            getPiece(i,j) = Piece();
        }
    }
}

void Grid::display() {
    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++) {
            Piece tmpPiece = getPiece(i,j);
            switch (tmpPiece.getType()) {
                case Type::None: cout << "| " << i * 3 + j + 1 << " "; break;
                case Type::O: {
                    if (tmpPiece.getAge() == 1) {cout << "|\033[1;35m O \033[0m"; break;}
                    cout << "|\033[1;31m O \033[0m"; break;
                }
                case Type::X: {
                    if (tmpPiece.getAge() == 1) {cout << "|\033[1;36m X \033[0m"; break;}
                    cout << "|\033[1;34m X \033[0m"; break;
                }
            }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void Grid::setPiece(int row, int col, Type t) {
    getPiece(row,col).setType(t);
    getPiece(row,col).setAge(7);
}

Piece& Grid::getPiece(int row, int col) {
    return grid[row][col];
}

int Grid::numPiece(Type t) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (getPiece(i,j).getType() == t) counter++;
        }
    }
    return counter;
}

void Grid::setAllPieces() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (getPiece(i,j).getAge() == 0) continue;
            else getPiece(i,j).loseAge();
        }
    }
}

void Grid::input(Type t, int turn) {

    if (turn % 2 == 0) cout << "\033[4;31mRed\033[0m,it's your turn. \n\033[1;31mGO!\033[0m" << endl;
    else cout << "\033[4;34mBlue\033[0m,it's your turn. \n\033[1;34mGO!\033[0m" << endl;
    int pos;
    cout << "Where do you want to place it?" << endl;
    cin >> pos;
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (pos < 1 || pos > 9) {
        while (true) {
            cout << "Choose one between 1 - 9." <<endl;
            cin >> pos;
            if (pos > 0 && pos < 10) break;
        }
    }
    if (getPiece(row, col).getType() != Type::None) {
        while (true) {
            cout << "Oops! Choose a \033[1;33mnon-occupied \033[0mplace!" << endl;
            cin >> pos;
            row = (pos - 1) / 3;
            col = (pos - 1) % 3;
            if (getPiece(row, col).getType() == Type::None) break;
        }
    }
    setPiece(row, col, t);
}

bool Grid::gameFinished(Type& winner) {
    // Diagonal
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        winner = getPiece(1,1).getType();
        return true;
    } else if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) {
        winner = getPiece(1,1).getType();
        return true;
    }
    // Rows and columns
    int ind = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ind > i || ind > j) continue;
            if (getPiece(i,j).getType() == Type::None) {
                ind++;
                continue;
            }
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                winner = getPiece(i,1).getType();
                return true;
            } else if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
                winner = getPiece(1,j).getType();
                return true;
            }
        }
    }
    return false;
}

void Grid::setOneRandomPiece(Type t) {
    if (numPiece(Type::None) == 0) return;
    bool done = false;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 8);
    while (!done) {
        int tmpCase = distrib(gen);
        int row = tmpCase / 3;
        int col = tmpCase % 3;
        if (getPiece(row,col).getType() != Type::None) {
            continue;
        } else {
            setPiece(row, col, t);
            done = true;
        }
    }
}

void Grid::getStatus() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "cell " << i << " - " << j << " : ";
            switch (getPiece(i,j).getType()) {
                case Type::None: cout << "None"; break;
                case Type::O: cout << "O"; break;
                case Type::X: cout << "X"; break;
            }
            cout << " age : " << getPiece(i,j).getAge() << endl;
        }
    }
}

void winAnounce (Type t) {
    cout << "The Winner is ";
    switch (t) {
        case Type::O : cout << "\033[1;31mRED\033[0m!" << endl; break;
        case Type::X : cout << "\033[1;34mBLUE\033[0m!" << endl; break;
        default : cout << "Oops! Something Went \033[1;31mWrong\033[0m!" << endl; break;
    }
}

int distribTurn() {
    cout << "Choose the \033[1;33mfirst player\033[0m's Color :)" << endl;
    cout << "0 : \033[1;31mO\033[0m (\033[4;31mRED\033[0m)" << endl;
    cout << "1 : \033[1;34mX\033[0m (\033[4;34mBLUE\033[0m)" << endl;
    int n;
    cin >> n;
    while (n != 0 && n != 1) {
        cout << "HOW DARE YOU??..." <<endl;
        cout << "This is just a basic sample of the game" << endl;
        cout << "Chill Dude :) .. Just choose \033[1;33m0\033[0m or \033[1;33m1\033[0m" << endl;
        cin >> n;
    }
    cout << "Great!\n So :" << endl;
    if (n==0) {
        cout << "\033[1;31mRed\033[0m is the first to play and\n\033[1;34mBlue\033[0m is the second!\n Here We Go" << endl;
    } else {
        cout << "\033[1;34mBlue\033[0m is the first to play and\n\033[1;31mRed\033[0m is the second!\n Here We Go" << endl;
    }
    return n;
}

Grid testGridWinningRow() {
    Grid test;
    test.setPiece(0, 0, Type::O);
    test.setPiece(0, 1, Type::O);
    test.setPiece(0, 2, Type::O);
    return test;
}

Grid testGridWinningColumn() {
    Grid test;
    test.setPiece(0, 0, Type::O);
    test.setPiece(1, 0, Type::O);
    test.setPiece(2, 0, Type::O);
    return test;
}

Grid testGridWinningDiagonal() {
    Grid test;
    test.setPiece(0, 0, Type::O);
    test.setPiece(1, 1, Type::O);
    test.setPiece(2, 2, Type::O);
    return test;
}

Grid testGrid() {
    Grid test;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (distrib(gen)) {
                case 0: test.setPiece(i, j, Type::None); break;
                case 1: test.setPiece(i, j, Type::O); break;
                case 2: test.setPiece(i, j, Type::X); break;
            }
        }
    }
    return test;
}