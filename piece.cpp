#include "piece.hpp"

Piece::Piece () : _type{Type::None}, age{4} {}

Type Piece::getType () {
    return _type;
}

void Piece::setType (Type t) {
    _type = t;
}

void Piece::setAge (int n) {
    if (age!=0) age--;
    else throw range_error ("The piece's existance's age is out of range!");
}