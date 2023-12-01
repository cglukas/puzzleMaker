#ifndef PUZZLECREATOR_H
#define PUZZLECREATOR_H

#include "puzzle.h"


class PuzzleCreator
{
public:
    PuzzleCreator();
    Puzzle generateGridPuzzle(int count_x, int count_y, int width, int height);
};

#endif // PUZZLECREATOR_H
