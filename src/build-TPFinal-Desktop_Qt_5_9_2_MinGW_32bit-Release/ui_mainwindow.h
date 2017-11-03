/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *from_1;
    QLabel *to_1;
    QLabel *date_1;
    QLabel *subject_1;
    QPushButton *act_button;
    QLabel *from_2;
    QLabel *to_2;
    QLabel *date_2;
    QLabel *subject_2;
    QLabel *from_3;
    QLabel *to_3;
    QLabel *date_3;
    QLabel *subject_3;
    QLabel *from_4;
    QLabel *to_4;
    QLabel *date_4;
    QLabel *subject_4;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(597, 482);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 290, 101, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 161, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 151, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 151, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 151, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 151, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 210, 151, 31));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 80, 161, 31));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 130, 161, 31));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 180, 161, 31));
        textEdit_5 = new QTextEdit(centralWidget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(10, 240, 161, 41));
        from_1 = new QLabel(centralWidget);
        from_1->setObjectName(QStringLiteral("from_1"));
        from_1->setGeometry(QRect(220, 20, 81, 31));
        to_1 = new QLabel(centralWidget);
        to_1->setObjectName(QStringLiteral("to_1"));
        to_1->setGeometry(QRect(320, 20, 81, 31));
        date_1 = new QLabel(centralWidget);
        date_1->setObjectName(QStringLiteral("date_1"));
        date_1->setGeometry(QRect(420, 20, 81, 31));
        subject_1 = new QLabel(centralWidget);
        subject_1->setObjectName(QStringLiteral("subject_1"));
        subject_1->setGeometry(QRect(510, 20, 81, 31));
        act_button = new QPushButton(centralWidget);
        act_button->setObjectName(QStringLiteral("act_button"));
        act_button->setGeometry(QRect(270, 290, 80, 31));
        from_2 = new QLabel(centralWidget);
        from_2->setObjectName(QStringLiteral("from_2"));
        from_2->setGeometry(QRect(220, 80, 81, 31));
        to_2 = new QLabel(centralWidget);
        to_2->setObjectName(QStringLiteral("to_2"));
        to_2->setGeometry(QRect(320, 80, 81, 31));
        date_2 = new QLabel(centralWidget);
        date_2->setObjectName(QStringLiteral("date_2"));
        date_2->setGeometry(QRect(420, 80, 81, 31));
        subject_2 = new QLabel(centralWidget);
        subject_2->setObjectName(QStringLiteral("subject_2"));
        subject_2->setGeometry(QRect(510, 80, 81, 31));
        from_3 = new QLabel(centralWidget);
        from_3->setObjectName(QStringLiteral("from_3"));
        from_3->setGeometry(QRect(220, 140, 81, 31));
        to_3 = new QLabel(centralWidget);
        to_3->setObjectName(QStringLiteral("to_3"));
        to_3->setGeometry(QRect(320, 140, 81, 31));
        date_3 = new QLabel(centralWidget);
        date_3->setObjectName(QStringLiteral("date_3"));
        date_3->setGeometry(QRect(420, 140, 81, 31));
        subject_3 = new QLabel(centralWidget);
        subject_3->setObjectName(QStringLiteral("subject_3"));
        subject_3->setGeometry(QRect(510, 140, 81, 31));
        from_4 = new QLabel(centralWidget);
        from_4->setObjectName(QStringLiteral("from_4"));
        from_4->setGeometry(QRect(220, 200, 81, 31));
        to_4 = new QLabel(centralWidget);
        to_4->setObjectName(QStringLiteral("to_4"));
        to_4->setGeometry(QRect(320, 200, 81, 31));
        date_4 = new QLabel(centralWidget);
        date_4->setObjectName(QStringLiteral("date_4"));
        date_4->setGeometry(QRect(420, 200, 81, 31));
        subject_4 = new QLabel(centralWidget);
        subject_4->setObjectName(QStringLiteral("subject_4"));
        subject_4->setGeometry(QRect(510, 200, 81, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 290, 81, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Agregar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "To", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Subject", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Content", Q_NULLPTR));
        from_1->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        to_1->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        date_1->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        subject_1->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        act_button->setText(QApplication::translate("MainWindow", "Actualizar", Q_NULLPTR));
        from_2->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        to_2->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        date_2->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        subject_2->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        from_3->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        to_3->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        date_3->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        subject_3->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        from_4->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        to_4->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        date_4->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        subject_4->setText(QApplication::translate("MainWindow", "From", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
