#include "piece.hpp"

Piece::Piece () type{Type::None} {}

Type Piece::getType () {
    return type;
}