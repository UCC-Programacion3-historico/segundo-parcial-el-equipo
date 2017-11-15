#include "mainwindow.h"
#include "ui_mainwindow.h"

MailManager* MM;
int cont=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
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

    QString aux;

    aux = ui->textEdit->toPlainText();
    A.from = aux.toStdString();
    ui->textEdit->setText("");
    aux = ui->textEdit_2->toPlainText();
    A.to = aux.toStdString();
    ui->textEdit_2->setText("");
    aux = ui->textEdit_3->toPlainText();
    A.date = aux.toStdString();
    ui->textEdit_3->setText("");
    aux = ui->textEdit_4->toPlainText();
    A.subject = aux.toStdString();
    ui->textEdit_4->setText("");
    aux = ui->textEdit_5->toPlainText();
    A.content = aux.toStdString();
    ui->textEdit_5->setText("");

    A.id = cont;
    cont++;

    MM->addMail(A);
}

void MainWindow::on_act_button_clicked()
{
    vector<email> A;
    QString aux;
    A = MM->getSortedByFrom();

    switch (A.size()) {
    default:
        aux = QString::fromStdString(A[3].from);
        ui->from_4->setText(aux);
        aux = QString::fromStdString(A[3].to);
        ui->to_4->setText(aux);
        aux = QString::fromStdString(A[3].date);
        ui->date_4->setText(aux);
        aux = QString::fromStdString(A[3].subject);
        ui->subject_4->setText(aux);
    case 3:
        aux = QString::fromStdString(A[2].from);
        ui->from_3->setText(aux);
        aux = QString::fromStdString(A[2].to);
        ui->to_3->setText(aux);
        aux = QString::fromStdString(A[2].date);
        ui->date_3->setText(aux);
        aux = QString::fromStdString(A[2].subject);
        ui->subject_3->setText(aux);
    case 2:
        aux = QString::fromStdString(A[1].from);
        ui->from_2->setText(aux);
        aux = QString::fromStdString(A[1].to);
        ui->to_2->setText(aux);
        aux = QString::fromStdString(A[1].date);
        ui->date_2->setText(aux);
        aux = QString::fromStdString(A[1].subject);
        ui->subject_2->setText(aux);
    case 1:
        aux = QString::fromStdString(A[0].from);
        ui->from_1->setText(aux);
        aux = QString::fromStdString(A[0].to);
        ui->to_1->setText(aux);
        aux = QString::fromStdString(A[0].date);
        ui->date_1->setText(aux);
        aux = QString::fromStdString(A[0].subject);
        ui->subject_1->setText(aux);
    case 0:
        break;
    }
}

void MainWindow::on_pushButton_3_clicked(){

}

void MainWindow::on_pushButton_2_clicked()
{
    MM->deleteMail(2333333);
    cont--;
    if(cont < 0){
        cont = 0;
    }
    ui->date_1->setText("");
    ui->date_2->setText("");
    ui->date_3->setText("");
    ui->date_4->setText("");
    ui->from_1->setText("");
    ui->from_2->setText("");
    ui->from_3->setText("");
    ui->from_4->setText("");
    ui->to_1->setText("");
    ui->to_2->setText("");
    ui->to_3->setText("");
    ui->to_4->setText("");

}
