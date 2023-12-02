#include "doctest.h"
#include "edge.h"

/**
 * Initialize the edge with two vertecies.
 *
 * The vertex with the lower sum of it's coordinates will be set as the start vertex.
 * @brief Edge::Edge
 * @param start_
 * @param end_
 */
Edge::Edge(Vertex *v1, Vertex *v2){
    if(v1->getX()+v1->getY()>v2->getX()+v2->getY()){
        start = v2;
        end = v1;
    }  else{
        start = v1;
        end = v2;
    }
};

TEST_CASE("Edge equality"){
    Vertex *v1 = new Vertex(0,0);
    Vertex *v2 = new Vertex(0,10);

    // The order of points should not matter for the equality of edges.
    CHECK(Edge(v1, v2) == Edge(v2, v1));
}

