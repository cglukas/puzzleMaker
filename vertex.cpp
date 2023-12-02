#include "doctest.h"
#include "vertex.h"

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

TEST_CASE("Test equality"){
    CHECK(Vertex() == Vertex());
    CHECK(Vertex() == Vertex(0, 0));
    CHECK(Vertex(1,2) == Vertex(1,2));
    CHECK(Vertex(-1,0) == Vertex(-1,0));
}


TEST_CASE("Test inequality"){
    CHECK(Vertex(0, 0) != Vertex(0, 5));
    CHECK(Vertex(1,2) != Vertex(2,1));
    CHECK(Vertex(-1,0) != Vertex(900,900));
}

std::ostream &operator<<(std::ostream& os, Vertex const & v){
    os<<"Vertex("<< v.x << ", " << v.y << ")";
    return os;
}
