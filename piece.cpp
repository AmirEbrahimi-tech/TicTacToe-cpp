#include "piece.hpp"

Piece::Piece() : _type{Type::None}, age{0} {}

Type Piece::getType() {
    return _type;
}

void Piece::setType(Type t) {
    _type = t;
}

int Piece::getAge() {
    return age;
}

void Piece::setAge(int n) {
    age = n;
}

void Piece::loseAge() {
    if (age != 0) age--;
    if (age == 0) this->setType(Type::None);
}

bool Piece::operator==(Piece& p) const {
    return (_type == p.getType() && _type != Type::None);
}

bool Piece::operator!=(Piece& p) const {
    return !(*this == p);
}