#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{
private:
    Vertex *start;
    Vertex *end;
public:
    explicit Edge(Vertex *v1, Vertex *v2);;
    bool operator==(Edge const & other) const {
        return this->start == other.start && this->end == other.end;
    };
};

#endif // EDGE_H
