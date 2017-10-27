#include "addmaildialog.h"
#include "ui_addmaildialog.h"

AddMailDialog::AddMailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMailDialog)
{
    ui->setupUi(this);
}

AddMailDialog::~AddMailDialog()
{
    delete ui;
}

void AddMailDialog::on_buttonBox_accepted()
{

}
