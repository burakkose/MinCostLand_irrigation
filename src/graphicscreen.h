#ifndef GRAPHICSCREEN_H
#define GRAPHICSCREEN_H

#include <QDialog>

namespace Ui {
class GraphicScreen;
}

class GraphicScreen : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicScreen(QWidget *parent = 0);
    ~GraphicScreen();

private:
    Ui::GraphicScreen *ui;
};

#endif // GRAPHICSCREEN_H
