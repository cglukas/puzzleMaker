#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QWidget>

class PuzzleView : public QWidget
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *event);
public:
    explicit PuzzleView(QWidget *parent = nullptr);
signals:
};

#endif // PUZZLEVIEW_H
