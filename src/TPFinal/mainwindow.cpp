#include "mainwindow.h"
#include "ui_mainwindow.h"

MailManager* MM;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Primero que nada deberia levantar de la base de datos los otros mails y crear las tablas de busqueda
    try {
        MM = new MailManager();
    } catch(int e) {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(MM->tablaMails[0].subject);
}
