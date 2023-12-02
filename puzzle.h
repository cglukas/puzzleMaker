#ifndef PUZZLE_H
#define PUZZLE_H

#include "puzzle_piece.h"


class Puzzle
{
private:
    std::vector<PuzzlePiece> pieces;
public:
    Puzzle();
    Puzzle(std::vector<PuzzlePiece> pieces);
    std::vector<PuzzlePiece> getPieces();
    void addPiece(PuzzlePiece piece);
};

#endif // PUZZLE_H
