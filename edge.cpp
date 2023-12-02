#include "doctest.h"
#include "edge.h"


/**
 * Get a vertex along the edge.
 * @brief Edge::getVertexOnEdge
 * @param percentage from the start point where the point on the edge should be returned.
 * @return
 */
Vertex Edge::getVertexOnEdge(int percentage)
{
    double percent = percentage / 100.0;

    double x;
    if(start.getX() < end.getX()){
        x = start.getX() + percent * (end.getX() - start.getX());
    }else{
        x = end.getX() + percent * (start.getX() - end.getX());
    }

    double y;
    if(start.getY() < end.getY()){
        y = start.getY() + percent * (end.getY() - start.getY());
    }else{
        y = end.getY() + percent * (start.getY() - end.getY());
    }

    return Vertex(x, y);
}

TEST_CASE("Get vertecies on the edge") {

    SUBCASE("Edge length 10") {
        Edge e(Vertex(0,0), Vertex(0, 10));
        CHECK(e.getVertexOnEdge(50) == Vertex(0,5));
        CHECK(e.getVertexOnEdge(55) == Vertex(0,5));
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

    SUBCASE("Diagonal Edge length 100") {
        Edge e(Vertex(0,0), Vertex(100, 100));
        CHECK(e.getVertexOnEdge(50) == Vertex(50,50));
        CHECK(e.getVertexOnEdge(55) == Vertex(55,55));
        CHECK(e.getVertexOnEdge(0) == Vertex(0,0));
        CHECK(e.getVertexOnEdge(100) == Vertex(100,100));
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

