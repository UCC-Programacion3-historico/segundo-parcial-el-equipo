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
    email A;
    QString tmp;
    QByteArray tmp2;
    A.from = new char[20];
    A.to = new char[20];
    A.date = new char[10];
    A.subject = new char[50];
    A.content = new char[150];

    tmp = ui->textEdit->toPlainText();
    ui->textEdit->setText("");
    tmp2 = tmp.toLatin1();
    A.from = tmp2.data();
    tmp = ui->textEdit_2->toPlainText();
    ui->textEdit_2->setText("");
    tmp2 = tmp.toLatin1();
    A.to = tmp2.data();
    tmp = ui->textEdit_3->toPlainText();
    ui->textEdit_3->setText("");
    tmp2 = tmp.toLatin1();
    A.date = tmp2.data();
    tmp = ui->textEdit_4->toPlainText();
    ui->textEdit_4->setText("");
    tmp2 = tmp.toLatin1();
    A.subject = tmp2.data();
    tmp = ui->textEdit_5->toPlainText();
    ui->textEdit_5->setText("");
    tmp2 = tmp.toLatin1();
    A.content = tmp2.data();

    MM->addMail(A);
}

void MainWindow::on_pushButton_3_clicked()
{
    //email** A = MM->getSortedByDate();
    email* A = MM->arbolNuevosDate->getFirst(MM->arbolNuevosDate);
    ui->label_6->setText(A->from);
    ui->label_7->setText(A->to);
    ui->label_8->setText(A->date);
    //cont--;
    //if(cont<0){cont = 0;}
}

void MainWindow::on_pushButton_2_clicked()
{
    email** A = MM->getSortedByDate();
    ui->label_6->setText(A[cont]->from);
    ui->label_7->setText(A[cont]->to);
    ui->label_8->setText(A[cont]->date);
    cont++;
    if(cont>=(MM->sizeArbol+MM->sizeTablaMails)){cont = MM->sizeArbol + MM->sizeTablaMails -1;}
}
