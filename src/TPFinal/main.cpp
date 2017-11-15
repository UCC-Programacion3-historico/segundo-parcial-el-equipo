#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickWindow>

#include "email.h"
#include "handler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    Handler handler;

    email mails[10];

    mails[0].from = "alejanro";
    mails[0].date = "2015 12 16 03:44";


    mails[1].from = "ruiz";
    mails[1].subject = "holaa";
    mails[1].date = "2012 07 03 22:15";

    mails[2].from = "Boris";
    mails[2].subject = "Reunion";
    mails[2].date = "2013 01 01 10:11";

    mails[3].from = "zarate";
    mails[3].subject = "Trabajo";
    mails[3].date = "2017 11 14 22:15";

    mails[4].from = "marcelo";
    mails[4].subject = "Pile";
    mails[4].date = "2017 11 14 14:40";

    mails[5].from = "kolsch";
    mails[5].subject = "vamo a toma una birra";
    mails[5].date = "2017 12 10 20:55";

    mails[6].from = "sanz";
    mails[6].subject = "asdas";
    mails[6].date = "2002 03 03 09:09";

    mails[7].from = "ambrosio";
    mails[7].subject = "dale mono";
    mails[7].date = "2012 07 03 22:15";

    mails[8].from = "carlos";
    mails[8].date = "2002 11 14 22:15";

    mails[9].from = "diaz";
    mails[9].subject = "";
    mails[9].date = "2013 12 13 10:15";


    for (int i=0; i < 10; i++) {
        handler.addNewMail(mails[i]);
    }


    // Conexiones de Signals y Slots

    //Clear List
    QObject::connect(&handler, SIGNAL(clearListCPPSignal()),
                     window, SLOT(clearListQMLSlot()));

    //addMail Connections
    QObject::connect(window, SIGNAL(addNewMailQMLSignal(QString, QString, QString, QString, QString, bool)),
                         &handler, SLOT(addNewMailCPPSlot(QString,QString,QString,QString,QString,bool)));

    QObject::connect(&handler, SIGNAL(addItemToListViewCPPSignal(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)),
                     window, SLOT(updateListQMLSlot(QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant)));

    // setMailsDateInterval Connections
    QObject::connect(window, SIGNAL(setMailsIntervalQMLSignal(QString, QString)),
                         &handler, SLOT(setMailsDateIntervalCPPSlot(QString,QString)));

    // sortBySender connections

        QObject::connect(window, SIGNAL(sortByDateQMLSignal()),
                             &handler, SLOT(sortByDateCPPSlot()));

        QObject::connect(window, SIGNAL(sortBySenderQMLSignal()),
                                     &handler, SLOT(sortBySenderCPPSlot()));
    // Searching connections

        QObject::connect(window, SIGNAL(searchByQueryQMLSignal(QString)),
                             &handler, SLOT(searchByQueryCPPSlot(QString)));

        QObject::connect(window, SIGNAL(searchBySenderQMLSignal(QString)),
                                     &handler, SLOT(searchBySenderCPPSlot(QString)));



    handler.initListView();

    return app.exec();
}
