#include "puzzleview.h"

#include <QPaintEvent>
#include <QPainter>

PuzzleView::PuzzleView(QWidget *parent)
    : QWidget{parent}
{}

/*
 * Set the puzzle pieces that should be drawn
 * */
void PuzzleView::drawPuzzlePieces(std::vector<PuzzlePiece> puzzle_pieces)
{
    this->puzzle_pieces = puzzle_pieces;
}


void PuzzleView::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    for(PuzzlePiece piece : puzzle_pieces){
        for(int i = 0; i < piece.getVertecies().size(); i++){
            Vertex v1 = piece.getVertecies()[i];
            int k = (i +1) % piece.getVertecies().size();
            Vertex v2 = piece.getVertecies()[k];

            painter.drawLine(v1.getX(), v1.getY(), v2.getX(), v2.getY());
        }

    }
}
