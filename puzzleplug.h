#ifndef PUZZLEPLUG_H
#define PUZZLEPLUG_H

#include "puzzle_piece.h"


class PuzzlePlug
{
private:
    PuzzlePiece *p1;
    PuzzlePiece *p2;
public:
    PuzzlePlug();
    PuzzlePlug(PuzzlePiece *_p1, PuzzlePiece *_p2): p1(_p1), p2(_p2) {};
    PuzzlePiece *getP1() {return p1;};
    PuzzlePiece *getP2() {return p2;};
    Vertex getPosition();
};


#endif // PUZZLEPLUG_H
