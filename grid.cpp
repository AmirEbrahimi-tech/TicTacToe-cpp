#include "grid.hpp"

using namespace std;
//using Grid = vector<vector<int>>;

Grid::Grid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = Piece();
        }
    }
}

void Grid::display() {
    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++) {
            switch (grid[i][j].getType()) {
                case Type::None: cout << "| " << i * 3 + j + 1 << " "; break;
                case Type::O: cout << "|\033[1;31m O \033[0m"; break;
                case Type::X: cout << "|\033[1;34m X \033[0m"; break;
            }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void Grid::setPiece(int row, int col, Type t) {
    grid[row][col].setType(t);
    grid[row][col].setAge(8);
}

Piece Grid::getPiece(int row, int col) {
    return grid[row][col];
}

int Grid::numPiece(Type t) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j].getType() == t) counter++;
        }
    }
    return counter;
}

void Grid::setAllPieces() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j].getAge() == 0) continue;
            else grid[i][j].loseAge();
        }
    }
}

void Grid::input(Type t) {
    int pos;
    cout << "Where do you want to put it?" << endl;
    cin >> pos;
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (getPiece(row, col).getType() != Type::None) {
        while (true) {
            cout << "Oops! Choose a \033[1;31mnon-occupied \033[0mplace!" << endl;
            cin >> pos;
            row = (pos - 1) / 3;
            col = (pos - 1) % 3;
            if (getPiece(row, col).getType() == Type::None) break;
        }
    }
    setPiece(row, col, t);
}

bool Grid::gameFinished() {
    // Diagonal
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return true;
    else if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) return true;
    // Rows and columns
    int ind = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ind > i || ind > j) continue;
            if (grid[i][j].getType() == Type::None) {
                ind++;
                continue;
            }
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return true;
            else if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) return true;
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
        if (grid[row][col].getType() != Type::None) {
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
            switch (grid[i][j].getType()) {
                case Type::None: cout << "None"; break;
                case Type::O: cout << "O"; break;
                case Type::X: cout << "X"; break;
            }
            cout << " age : " << grid[i][j].getAge() << endl;
        }
    }
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