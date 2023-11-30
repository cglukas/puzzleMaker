#include "puzzle_piece.h"

PuzzlePiece::PuzzlePiece() {}

void PuzzlePiece::addVertex(int x, int y)
{
    vertecies.push_back(Vertex(x,y));
}

void PuzzlePiece::addVertex(Vertex v)
{
    vertecies.push_back(v);
}

std::vector<Vertex> PuzzlePiece::getVertecies()
{
    return vertecies;
}

