#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addmaildialog.h"

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

void MainWindow::on_pushButton_clicked()
{
    AddMailDialog addMailDialog;
    addMailDialog.setModal(true);
    addMailDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->searchLineEdit->setText("Deberia buscar");
}
