#ifndef PUZZLE_PIECE_H
#define PUZZLE_PIECE_H

#include "vertex.h"

#include <vector>
#include <QPoint>

class PuzzlePiece
{
public:
    PuzzlePiece();
    void addVertex(int x, int y);
    void addVertex(Vertex v);
    std::vector<Vertex> getVertecies();
private:
    std::vector<Vertex> vertecies;
};

#endif // PUZZLE_PIECE_H
