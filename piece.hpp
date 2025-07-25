#ifndef PIECE_HPP
#define PIECE_HPP

enum class Type {
    None,
    X,
    O
};

class Piece {
    public:
        Piece();
        Type getType();
        void setType(Type t);
        int getAge();
        void setAge(int n);
        void loseAge();
        bool operator==(Piece& p) const;
        bool operator!=(Piece& p) const;

    private:
        Type _type;
        int age;
};

#endif