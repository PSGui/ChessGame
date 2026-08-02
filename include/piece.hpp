#ifndef PIECE_HPP
#define PIECE_HPP

enum class PieceType
{
        Empty,
        Pawn,
        Rook,
        Knight,
        Bishop,
        Queen,
        King
};

enum class PieceColor
{
        None,
        White,
        Black
};

struct Piece
{
        PieceType type;
        PieceColor color;
};

#endif