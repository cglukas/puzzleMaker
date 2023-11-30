#ifndef PUZZLECREATOR_H
#define PUZZLECREATOR_H

#include "puzzle_piece.h"


class PuzzleCreator
{
public:
    PuzzleCreator();
    std::vector<PuzzlePiece> generateGridPuzzle(int count_x, int count_y, int width, int height);
};

#endif // PUZZLECREATOR_H
