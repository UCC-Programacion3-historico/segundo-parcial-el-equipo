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


    // Conexiones de Signals y Slots

    QObject::connect(window, SIGNAL(addNewMailQMLSignal(QString, QString, QString, QString, QString, bool)),
                         &handler, SLOT(addNewMailCPPSlot(QString,QString,QString,QString,QString,bool)));

    QObject::connect(&handler, SIGNAL(addItemToListViewCPPSignal(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)),
                     window, SLOT(updateListQMLSlot(QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant)));

    QObject::connect(&handler, SIGNAL(clearListCPPSignal()),
                     window, SLOT(clearListQMLSlot()));


    return app.exec();
}
