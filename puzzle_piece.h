#ifndef PUZZLE_PIECE_H
#define PUZZLE_PIECE_H

#include "edge.h"
#include "vertex.h"
#include <vector>
#include <QPoint>
#include "puzzleplug.h"

class PuzzlePiece
{
private:
    int id;
    static int current_id;
    std::vector<Vertex> vertecies;
    std::vector<PuzzlePlug> input_plugs;
    std::vector<PuzzlePlug> output_plugs;

public:
    PuzzlePiece(): id(current_id++) {};
    void addVertex(int x, int y);
    void addVertex(Vertex v);
    std::vector<Vertex> getVertecies();
    std::vector<Edge> getEdges();
    void connectToPiece(PuzzlePiece other);
    std::vector<PuzzlePlug> getInputPlugs() {return input_plugs; };
    std::vector<PuzzlePlug> getOutputPlugs() {return output_plugs; };
    bool operator==(PuzzlePiece const & other) const {
        return this->id == other.id;
    }
    bool operator!=(PuzzlePiece const & other) const {
        return this->id != other.id;
    }
};

#endif // PUZZLE_PIECE_H
