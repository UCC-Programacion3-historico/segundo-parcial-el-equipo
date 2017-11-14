#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QDebug>

class Handler : public QObject
{

    Q_OBJECT
public:
    explicit Handler(QObject *parent = 0);

    void addMail(QString, QString);
    void initListView();

private:
    QList<QString> mailList;

public slots:
    void slotClear();

signals:
    void clearListSignal();
};

#endif // HANDLER_H
