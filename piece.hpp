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
        int getAge ();
        void setAge (int n);
        void loseAge ();
        bool operator==(Piece& p) const;
        bool operator!=(Piece& p) const;

    private:

        Type _type;
        int age;

};

#endif