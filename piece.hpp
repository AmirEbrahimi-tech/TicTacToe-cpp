#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

enum class Type {X, O, None};

class Piece {

    public:

        Piece ();
        Type getType ();

    private:

        Type type;

};

#endif