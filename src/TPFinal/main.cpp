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

    mails[0].from = "alejanro@gmail.com";
    mails[0].to = "boris@live.com";
    mails[0].date = "2015 12 16 03:44";
    mails[0].content = "Material icons are beautifully crafted, delightful, and easy to use in your web, Android, and iOS projects. Learn more about material design and our process for making these icons in the system icons section of the ";


    mails[1].from = "ruiz@live.com";
    mails[1].to = "boris@live.com";
    mails[1].subject = "holaa";
    mails[1].date = "2012 07 03 22:15";
    mails[1].content = "You've installed Babel, but you haven't 'plugged it in' to your React app yet. You need to set up a system in which your React app will automatically run through Babel and compile your JSX, before reaching the browser. Also, JSX to JavaScript is just one of many transformations that will need to happen to your React code. You need to set up a 'transformation manager' that will take your code and run it through all of the transformations that you need, in the right order. How do you make that happen? There are a lot of different software packages that can make this happen.";;


    mails[2].from = "boris@live.com";
    mails[2].subject = "Reunion";
    mails[2].date = "2013 01 01 10:11";
    mails[2].to = "boris@live.com";
    mails[2].content = "Webpack's job is to run your React code through various transformations. Webpack needs to know exactly what transformations it should use! You can set that information by making a special webpack configuration file. This file must be located in the outermost layer of your root directory, and must be named webpack.config.js. It is where you will put all of the details required to make webpack operate.";

    mails[3].from = "zarate@yahoo.com.ar";
    mails[3].to = "kolsch@icloud.uk";
    mails[3].subject = "Trabajo";
    mails[3].date = "2017 11 14 22:15";
    mails[3].content = "At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores et quas molestias excepturi sint occaecati cupiditate non provident, similique sunt in culpa qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio cumque nihil impedit quo minus id quod maxime placeat facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";

    mails[4].from = "marcelo@gmail.com";
    mails[4].to = "kolsch@icloud.uk";
    mails[4].subject = "Pile";
    mails[4].date = "2017 11 14 14:40";
    mails[4].content = "At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores et quas molestias excepturi sint occaecati cupiditate non provident, similique sunt in culpa qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio cumque nihil impedit quo minus id quod maxime placeat facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";

    mails[5].from = "kolsch@icloud.uk";
    mails[5].to = "marcelo@gmail.com";
    mails[5].subject = "vamo a toma una birra";
    mails[5].date = "2017 12 10 20:55";
    mails[5].content = "Hola Gente. Estoy necesitando un estudiante de electrónica o carrera afín. Es para cubrir un puesto en mi empresa al menos hasta fin de año. La idea es tener a alguien que:Pueda interpretar/modificar programas para PIC en MPLAB.Interpretar/modificar esquemáticos y PCBRealizar testeo y reparación de equipos.Realizar algunos manuales. Dar asistencia a técnicos que están haciendo trabajos en la calle.Si a alguno  le interesa o conoce a alguien me avisa. Saludos";

    mails[6].from = "sanz@hotmail.com";
    mails[6].subject = "asdas";
    mails[6].to = "carlos@hotmail.com";
    mails[6].date = "2002 03 03 09:09";
    mails[6].content = "Holaaa, tanto tiempo!!!";

    mails[7].from = "ambrosio@gmail.com";
    mails[7].subject = "dale mono";
    mails[7].date = "2012 07 03 22:15";
    mails[7].to = "boris@live.com";
    mails[7].content = "Andas desaparecido borisss!!!";

    mails[8].from = "carlos@hotmail.com";
    mails[8].to = "diaz@gmail.com";
    mails[8].date = "2002 11 14 22:15";
    mails[8].content = "holaa diaz queridoo!! maestrooo";

    mails[9].from = "diaz@gmail.com";
    mails[9].subject = "";
    mails[9].to = "boris@live.com";
    mails[9].date = "2013 12 13 10:15";
    mails[9].content = "dale que va borisss";


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

    // delete email connection

    QObject::connect(window, SIGNAL(deleteMailQMLSignal(int, bool)),
                                 &handler, SLOT(deleteMailCPPSlot(int,bool)));

    // clear show mail connection

    QObject::connect(&handler, SIGNAL(clearShowMailCPPSignal()),
                                 window, SLOT(clearShowMailQMLSlot()));





    handler.initListView();

    return app.exec();
}
