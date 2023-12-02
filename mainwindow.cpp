#include "mainwindow.h"
#include "puzzlecreator.h"
#include "puzzleview.h"
#include "puzzlewriter.h"

#include <qboxlayout.h>
#include <qpushbutton.h>
#include <QMenuBar>
#include <QFileDialog>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    puzzle_view = new PuzzleView();

    PuzzleCreator creator;
    puzzle = creator.generateGridPuzzle(10, 8, 100, 80);
}

MainWindow::~MainWindow() {}

/**
 * Create the main menus of the puzzle maker ui
 * */
void MainWindow::createMenus()
{
    auto fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *save = new QAction("Save Puzzle...");
    QObject::connect(save, SIGNAL(triggered()), this, SLOT(saveWithDialog()));

    fileMenu->addAction(save);
}

/**
 * Show the puzzle to a user selected dialog.
 * @brief MainWindow::saveWithDialog
 */
void MainWindow::saveWithDialog()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("SVG (*.svg)"));
    if(fileName == ""){
        return;
    }
    if(!fileName.endsWith(".svg")){
        fileName.append(".svg");
    }
    PuzzleWriter puzzle_writer(fileName.toStdString(), puzzle);
    puzzle_writer.savePuzzle();
}


/**
 * Build the main user interface for the mainwindow.
 * */
void MainWindow::buildUI(){
    createMenus();
    QWidget *main_widget = new QWidget();
    setCentralWidget(main_widget);
    QVBoxLayout *layout = new QVBoxLayout();
    main_widget->setLayout(layout);

    layout->addWidget(puzzle_view);
    puzzle_view->drawPuzzlePieces(puzzle.getPieces());
}
