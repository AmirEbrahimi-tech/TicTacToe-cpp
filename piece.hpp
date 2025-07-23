#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

using namespace std;

enum class Type {X, O, None};

class Piece {

    public:

        Piece ();
        Type getType ();
        void setType (Type t);
        void setAge (int n);

    private:

        Type _type;
        int age;

};

#endif