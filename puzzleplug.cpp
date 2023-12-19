#include "doctest.h"
#include "puzzleplug.h"
#include "puzzle_piece.h"

#include <stdexcept>

TEST_CASE("Test puzzle pieces creation."){
    PuzzlePiece p1;
    PuzzlePiece p2;
    PuzzlePlug plug = PuzzlePlug(p1, p2);

    CHECK(plug.getP1() == p1);
    CHECK(plug.getP2() == p2);
}

/**
 * Get the position of the plug.
 * @brief PuzzlePlug::getPosition
 * @return
 */
Vertex PuzzlePlug::getPosition()
{
    auto edges1 = p1.getEdges();
    auto edges2 = p2.getEdges();

    if (edges1.empty() || edges2.empty()){
        throw std::runtime_error(
            "No matching edge found for puzzle pieces with no vertecies."
        );
    }
    Edge *matching_edge = nullptr;

    for(Edge e1 : edges1){
        for(Edge e2: edges2){
            if(e1 == e2){
                matching_edge = &e1;
                break;
            }
        }
    }

    if (matching_edge == nullptr){
        throw std::runtime_error(
            "No matching edge found between puzzle pieces."
        );
    }

    return matching_edge->getVertexOnEdge(50);
}


TEST_CASE("Get the plug position between two pieces"){
    PuzzlePiece p1;
    PuzzlePiece p2;
    PuzzlePlug plug(p1, p2);

    SUBCASE("First"){
        p1.addVertex(0, 0);
        p1.addVertex(0, 10);

        p2.addVertex(0,0);
        p2.addVertex(0, 10);

        CHECK(plug.getPosition() == Vertex(0, 5));
    }
    SUBCASE("Second"){
        p1.addVertex(0, 0);
        p1.addVertex(10, 10);

        p2.addVertex(0,0);
        p2.addVertex(10, 10);

        CHECK(plug.getPosition() == Vertex(5, 5));
    }
    SUBCASE("No matching edges"){
        p1.addVertex(0, 0);
        p1.addVertex(10, 10);

        p2.addVertex(0,0);
        p2.addVertex(0, 10);

        CHECK_THROWS_WITH_AS(
            plug.getPosition(),
            "No matching edge found between puzzle pieces.",
            std::runtime_error
            );
    }
    SUBCASE("No points in puzzle piece"){
        p1.addVertex(0, 0);
        p1.addVertex(10, 10);

        // p2 is still empty.

        CHECK_THROWS_WITH_AS(
            plug.getPosition(),
            "No matching edge found for puzzle pieces with no vertecies.",
            std::runtime_error
            );
    }
}
