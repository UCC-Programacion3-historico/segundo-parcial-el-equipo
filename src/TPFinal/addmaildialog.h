#ifndef ADDMAILDIALOG_H
#define ADDMAILDIALOG_H

#include <QDialog>

namespace Ui {
class AddMailDialog;
}

class AddMailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMailDialog(QWidget *parent = 0);
    ~AddMailDialog();

private:
    Ui::AddMailDialog *ui;
};

#endif // ADDMAILDIALOG_H
