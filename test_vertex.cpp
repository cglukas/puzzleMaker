#include "doctest.h"
#include "vertex.h"

/*
 * Basic test that vertecies can store their values.
 * */
TEST_CASE("Vertex can store x and y"){
    Vertex v(1,2);
    CHECK(v.getX() == 1);
    CHECK(v.getY()==2);
}
