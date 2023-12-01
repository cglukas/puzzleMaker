#ifndef PUZZLEWRITER_H
#define PUZZLEWRITER_H

#include "puzzle.h"

#include <String>


class PuzzleWriter
{
private:
    std::string filepath;
    Puzzle puzzle;
public:
    PuzzleWriter();
    PuzzleWriter(std::string filepath, Puzzle puzzle);
    int savePuzzle();
};

#endif // PUZZLEWRITER_H
