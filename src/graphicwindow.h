#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QDialog>
#include <QPainter>
#include "drawgraph.h"

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicWindow(QWidget *parent = 0);
    template<typename Type>
    void setLand(Type, Type, int);
    void paintEvent(QPaintEvent*);
    ~GraphicWindow();

private:
    Ui::GraphicWindow *ui;

protected:
    DrawGraph* land;

};

#endif // GRAPHICWINDOW_H
