#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include "puzzle_piece.h"
#include <QWidget>

class PuzzleView : public QWidget
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *event);
    std::vector<PuzzlePiece> puzzle_pieces;
public:
    explicit PuzzleView(QWidget *parent = nullptr);
    void drawPuzzlePieces(std::vector<PuzzlePiece> puzzle_pieces);
signals:
};

#endif // PUZZLEVIEW_H
