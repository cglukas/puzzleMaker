#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "puzzleview.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void buildUI();

private slots:
    void saveWithDialog();

private:
    void createMenus();
    void createPuzzleView();
    PuzzleView *puzzle_view;
    std::vector<PuzzlePiece> puzzle;
};
#endif // MAINWINDOW_H
