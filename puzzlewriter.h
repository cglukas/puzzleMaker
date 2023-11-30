#ifndef PUZZLEWRITER_H
#define PUZZLEWRITER_H

#include "puzzle_piece.h"

#include <String>


class PuzzleWriter
{
private:
    std::string filepath;
public:
    PuzzleWriter();
    PuzzleWriter(std::string filepath);
    int savePuzzle(std::vector<PuzzlePiece> pieces);
};

#endif // PUZZLEWRITER_H
