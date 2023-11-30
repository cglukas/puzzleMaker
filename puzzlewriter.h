#ifndef PUZZLEWRITER_H
#define PUZZLEWRITER_H

#include "puzzle_piece.h"

#include <String>


class PuzzleWriter
{
private:
    std::string filepath;
    std::vector<PuzzlePiece> pieces;
public:
    PuzzleWriter();
    PuzzleWriter(std::string filepath, std::vector<PuzzlePiece> pieces);
    int savePuzzle();
};

#endif // PUZZLEWRITER_H
