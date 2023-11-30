#include "vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Vertex::getX()
{
    return x;
}

int Vertex::getY()
{
    return y;
}
