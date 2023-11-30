#include "puzzleview.h"

#include <QPaintEvent>
#include <QPainter>

PuzzleView::PuzzleView(QWidget *parent)
    : QWidget{parent}
{}


void PuzzleView::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
}
