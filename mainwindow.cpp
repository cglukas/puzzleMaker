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
    setCentralWidget(my_view);
}
