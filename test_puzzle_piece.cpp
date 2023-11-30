#include "doctest.h"
#include "puzzle_piece.h"

TEST_CASE("Test puzzle piece with three vertecies."){
    PuzzlePiece p;
    p.addVertex(0, 1);
    p.addVertex(1, 1);
    p.addVertex(1, 0);
    CHECK(p.getVertecies().size() == 3);
}

TEST_CASE("Test that vertecies can't be added from outside."){
    PuzzlePiece p;

    p.getVertecies().push_back(Vertex(1, 2));

    CHECK(p.getVertecies().size() == 0);
}

TEST_CASE("Test that vertecies can be added direcly."){
    PuzzlePiece p;

    p.addVertex(Vertex(1,2));

    CHECK(p.getVertecies().size() == 1);
}
