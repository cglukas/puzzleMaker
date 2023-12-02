#include "doctest.h"
#include <cmath>
#include "edge.h"
/**
 * Get a vertex along the edge.
 * @brief Edge::getVertexOnEdge
 * @param percentage from the start point where the point on the edge should be returned.
 * @return
 */
Vertex Edge::getVertexOnEdge(int percentage)
{
    if(percentage<0){
        throw std::invalid_argument("Received negative percentage.");
    }
    if(percentage>100){
        throw std::invalid_argument("Received percentage above 100.");
    }

    double percent = percentage / 100.0;

    double x;
    if(start.getX() < end.getX()){
        x = start.getX() + percent * (end.getX() - start.getX());
    }else{
        x = start.getX() - percent * (start.getX() - end.getX());
    }

    double y;
    if(start.getY() < end.getY()){
        y = start.getY() + percent * (end.getY() - start.getY());
    }else{
        y = start.getY() - percent * (start.getY() - end.getY());
    }

    return Vertex(round(x), round(y));
}

TEST_CASE("Get vertecies on the edge") {

    SUBCASE("Edge length 10") {
        Edge e(Vertex(0,0), Vertex(0, 10));
        CHECK(e.getVertexOnEdge(50) == Vertex(0,5));
        // limited precission:
        CHECK(e.getVertexOnEdge(55) == Vertex(0,6));
        CHECK(e.getVertexOnEdge(0) == Vertex(0,0));
        CHECK(e.getVertexOnEdge(100) == Vertex(0,10));
    }

    SUBCASE("Edge length 100") {
        Edge e(Vertex(0,0), Vertex(0, 100));
        CHECK(e.getVertexOnEdge(50) == Vertex(0,50));
        CHECK(e.getVertexOnEdge(55) == Vertex(0,55));
        CHECK(e.getVertexOnEdge(0) == Vertex(0,0));
        CHECK(e.getVertexOnEdge(100) == Vertex(0,100));
    }

    SUBCASE("Flipped edge length 100") {
        Edge e(Vertex(0, 100), Vertex(0,0));
        CHECK(e.getVertexOnEdge(50) == Vertex(0,50));
        CHECK(e.getVertexOnEdge(55) == Vertex(0,45));
        CHECK(e.getVertexOnEdge(0) == Vertex(0,100));
        CHECK(e.getVertexOnEdge(100) == Vertex(0,0));
    }

    SUBCASE("Wrong percentage"){
        Edge e(Vertex(0,0), Vertex(0, 10));
        SUBCASE("Negative percentage"){
            CHECK_THROWS_WITH_AS(
                e.getVertexOnEdge(-1),
                "Received negative percentage.",
                std::invalid_argument
            );
        }
        SUBCASE("Percentage above 100"){
            CHECK_THROWS_WITH_AS(
                e.getVertexOnEdge(101),
                "Received percentage above 100.",
                std::invalid_argument
                );
        }
    }
}


int sum(Vertex v){
    return v.getX() + v.getY();
}

bool Edge::operator==(const Edge &other) const {

    Vertex this_start;
    Vertex this_end;

    if (sum(this->start) < sum(this->end)){
        this_start = this->start;
        this_end = this->end;
    }else{
        this_end = this->start;
        this_start = this->end;
    }

    Vertex other_start;
    Vertex other_end;

    if (sum(other.start) < sum(other.end)){
        other_start = other.start;
        other_end = other.end;
    }else{
        other_end = other.start;
        other_start = other.end;
    }

    return this_start == other_start && this_end == other_end;
};

TEST_CASE("Edge equality"){
    Vertex v1 = Vertex(0,0);
    Vertex v2 = Vertex(0,10);

    // The order of points should not matter for the equality of edges.
    CHECK(Edge(v1, v2) == Edge(v2, v1));
}

