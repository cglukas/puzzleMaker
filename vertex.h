#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
private:
    int x;
    int y;
public:
    Vertex(): x(0), y(0) {};
    Vertex(int x, int y);
    int getX();
    int getY();
    bool operator ==(Vertex const & other) const {
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(Vertex const & other) const {
        return this->x != other.x || this->y != other.y;
    }
};
#endif // VERTEX_H
