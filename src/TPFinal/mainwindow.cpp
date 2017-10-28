#include "mainwindow.h"
#include "ui_mainwindow.h"

MailManager* MM;

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
    ui->label->setText(MM->getTablaMails(0)->from);
    ui->label_2->setText(MM->getTablaMails(0)->to);
    ui->label_3->setText(MM->getTablaMails(0)->date);
    ui->label_4->setText(MM->getTablaMails(0)->subject);
    ui->label_5->setText(MM->getTablaMails(0)->content);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText(MM->getTablaMails(1)->from);
    ui->label_2->setText(MM->getTablaMails(1)->to);
    ui->label_3->setText(MM->getTablaMails(1)->date);
    ui->label_4->setText(MM->getTablaMails(1)->subject);
    ui->label_5->setText(MM->getTablaMails(1)->content);
}
