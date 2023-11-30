#include "mainwindow.h"
#include "puzzleview.h"

#include <qboxlayout.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{}

MainWindow::~MainWindow() {}

/*
 * Build the main user interface for the mainwindow.
 * */
void MainWindow::buildUI(){
    PuzzleView *my_view = new PuzzleView();
    PuzzlePiece p;
    p.addVertex(10,10);
    p.addVertex(10,100);
    p.addVertex(100,100);
    p.addVertex(100,10);
    PuzzlePiece r;
    r.addVertex(110,10);
    r.addVertex(110,100);
    r.addVertex(200,100);
    r.addVertex(200,10);
    my_view->drawPuzzlePieces({p,r});
    setCentralWidget(my_view);
}
