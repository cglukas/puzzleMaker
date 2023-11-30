#include "mainwindow.h"

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
    QPushButton *my_button = new QPushButton("HelloWorld");
    setCentralWidget(my_button);
}
