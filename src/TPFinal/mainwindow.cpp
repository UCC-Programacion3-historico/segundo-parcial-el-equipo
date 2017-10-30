#include "mainwindow.h"
#include "ui_mainwindow.h"

MailManager* MM;
int cont=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    //Primero que nada deberia levantar de la base de datos los otros mails y crear las tablas de busqueda
    try {
        MM = new MailManager();
    } catch (int e) {

    }
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(MM->getTablaOrdenadaFrom(cont)->from);
    ui->label_2->setText(MM->getTablaOrdenadaFrom(cont)->to);
    ui->label_3->setText(MM->getTablaOrdenadaFrom(cont)->date);
    ui->label_4->setText(MM->getTablaOrdenadaFrom(cont)->subject);
    ui->label_5->setText(MM->getTablaOrdenadaFrom(cont)->content);
    cont++;
    if(cont>6){cont = 6;}
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText(MM->getTablaOrdenadaFrom(cont)->from);
    ui->label_2->setText(MM->getTablaOrdenadaFrom(cont)->to);
    ui->label_3->setText(MM->getTablaOrdenadaFrom(cont)->date);
    ui->label_4->setText(MM->getTablaOrdenadaFrom(cont)->subject);
    ui->label_5->setText(MM->getTablaOrdenadaFrom(cont)->content);
    cont--;
    if(cont<0){cont = 0;}
}
