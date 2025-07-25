#ifndef GRID_HPP
#define GRID_HPP

#include <random>
#include <iostream>
#include "piece.hpp"

using namespace std;

class Grid {

    public:

        Grid();
        void display();
        void setPiece(int row, int col, Type t);
        Piece getPiece(int row, int col);
        int numPiece(Type t);
        void setAllPieces();
        void input(Type t);
        bool gameFinished();
        void setOneRandomPiece(Type t);
        void getStatus();

    private:

        // vector<vector<int>> grid;
        Piece grid[3][3];
};

Grid testGridWinningRow();

Grid testGridWinningColumn();

Grid testGridWinningDiagonal();

Grid testGrid();

#endif