#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{
private:
    Vertex start;
    Vertex end;
public:
    explicit Edge(Vertex start_, Vertex end_): start(start_), end(end_) {};
    Vertex getVertexOnEdge(int percentage);
    bool operator==(Edge const & other) const;;
};

#endif // EDGE_H
