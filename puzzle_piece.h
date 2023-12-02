#ifndef PUZZLE_PIECE_H
#define PUZZLE_PIECE_H

#include "edge.h"
#include "vertex.h"
#include <vector>
#include <QPoint>

class PuzzlePiece
{
private:
    int id;
    static int current_id;
    std::vector<Vertex> vertecies;

public:
    PuzzlePiece(): id(current_id++) {};
    void addVertex(int x, int y);
    void addVertex(Vertex v);
    std::vector<Vertex> getVertecies();
    std::vector<Edge> getEdges();
    bool operator==(PuzzlePiece const & other) const {
        return this->id == other.id;
    }
    bool operator!=(PuzzlePiece const & other) const {
        return this->id != other.id;
    }
};

#endif // PUZZLE_PIECE_H
