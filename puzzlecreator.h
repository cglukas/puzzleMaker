#ifndef PUZZLECREATOR_H
#define PUZZLECREATOR_H

#include "puzzle.h"


class PuzzleCreator
{
public:
    PuzzleCreator();
    Puzzle generateGridPuzzle(int count_x, int count_y, int width, int height);
    Puzzle generateVoronoiPuzzle(int count_pieces, int puzzle_width, int puzzle_height);
};

#endif // PUZZLECREATOR_H
