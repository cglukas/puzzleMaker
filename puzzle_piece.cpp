#include "doctest.h"
#include "puzzle_piece.h"


int PuzzlePiece::current_id;

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


TEST_CASE("PuzzlePiece equality comparison.") {
    PuzzlePiece p1;
    PuzzlePiece p2;

    CHECK(p1 == p1);
    CHECK(p1 != p2);
    CHECK(PuzzlePiece() != PuzzlePiece());
}
