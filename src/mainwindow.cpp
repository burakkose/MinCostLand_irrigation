#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <graph.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    ui->location->setText(QFileDialog::getOpenFileName(this, tr("Open File"),"/home",
                                                       tr("Document Files (*.txt)")));
    if(!ui->location->text().isEmpty()){
        ui->solveButton->setEnabled(true);
        ui->warningText->setVisible(false);
    }
}

void MainWindow::on_solveButton_clicked()
{
    Graph g;
    g.readFile(ui->location->text());
}
