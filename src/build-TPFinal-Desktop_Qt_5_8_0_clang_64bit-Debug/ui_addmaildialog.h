/********************************************************************************
** Form generated from reading UI file 'addmaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMAILDIALOG_H
#define UI_ADDMAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddMailDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QTextEdit *textEdit;

    void setupUi(QDialog *AddMailDialog)
    {
        if (AddMailDialog->objectName().isEmpty())
            AddMailDialog->setObjectName(QStringLiteral("AddMailDialog"));
        AddMailDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddMailDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AddMailDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 221, 21));
        lineEdit_2 = new QLineEdit(AddMailDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 60, 221, 21));
        lineEdit_3 = new QLineEdit(AddMailDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(260, 30, 121, 21));
        lineEdit_4 = new QLineEdit(AddMailDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(260, 60, 121, 21));
        textEdit = new QTextEdit(AddMailDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 100, 361, 121));

        retranslateUi(AddMailDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddMailDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddMailDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddMailDialog);
    } // setupUi

    void retranslateUi(QDialog *AddMailDialog)
    {
        AddMailDialog->setWindowTitle(QApplication::translate("AddMailDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddMailDialog: public Ui_AddMailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMAILDIALOG_H
