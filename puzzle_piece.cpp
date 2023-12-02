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

std::vector<Edge> PuzzlePiece::getEdges()
{
    int k = 0;
    std::vector<Edge> edges = {};

    for (int i =0; i<vertecies.size(); i++){
        k = (i+1) % vertecies.size();
        auto v1 = vertecies[i];
        auto v2 = vertecies[k];
        edges.push_back(Edge(v1, v2));
    }
    return edges;
}

TEST_CASE("PuzzlePiece vertecies can be retrieved as edges"){
    PuzzlePiece p;

    Vertex a(0,0);
    Vertex b(10, 10);
    Vertex c(0, 10);
    p.addVertex(a);
    p.addVertex(b);
    p.addVertex(c);

    auto edges = p.getEdges();

    // The three sides of the constructed triangle.
    // Puzzle pieces must be closed at all time.
    REQUIRE(edges.size() == 3);

    CHECK(edges[0] == Edge(a, b));
    CHECK(edges[1] == Edge(b, c));
    CHECK(edges[2] == Edge(c, a));
}


TEST_CASE("PuzzlePiece equality comparison.") {
    PuzzlePiece p1;
    PuzzlePiece p2;

    CHECK(p1 == p1);
    CHECK(p1 != p2);
    CHECK(PuzzlePiece() != PuzzlePiece());
}
