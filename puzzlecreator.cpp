#include "puzzlecreator.h"

PuzzleCreator::PuzzleCreator() {}

/**
 * Create a grid of puzzle pieces.
 * @brief PuzzleCreator::generateGridPuzzle
 * @param count_x number of pieces in x direction
 * @param count_y number of pieces in y direction
 * @param width size of the pieces in x direction
 * @param height size of the pieces in y direction
 * @return the created puzzle as a vector of puzzle pieces. Row by row.
 */
Puzzle PuzzleCreator::generateGridPuzzle(int count_x, int count_y, int width, int height)
{
    int x = 0;
    int y = 0;
    Puzzle puzzle;
    for(int row = 0; row < count_y; row++){
        for(int column = 0; column < count_x; column++){
            PuzzlePiece p;
            p.addVertex(x, y);
            p.addVertex(x + width, y);
            p.addVertex(x + width, y + height);
            p.addVertex(x, y + height);
            puzzle.addPiece(p);

            x += width;
        }
        x = 0;
        y += height;
    }

    return puzzle;
}

/**
 * Generate a puzzle with a voronoi structure.
 *
 * @brief PuzzleCreator::generateVoronoiPuzzle
 * @param count_pieces
 * @param puzzle_width
 * @param puzzle_height
 * @return
 */
Puzzle PuzzleCreator::generateVoronoiPuzzle(int count_pieces, int puzzle_width, int puzzle_height)
{
    return Puzzle();
}
