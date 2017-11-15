#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QDebug>
#include <vector>

#include "MailManager.h"
#include "email.h"


class Handler : public QObject
{

    Q_OBJECT
public:
    explicit Handler(QObject *parent = 0);

    void addNewMail(email);
    void initListView();
    void updateListView();

private:

    MailManager mailManager;
    vector<email> mailListToRender;
    email mailToAdd;
    int count;

public slots:
    void addNewMailCPPSlot(const QString &from, const QString &to,
                            const QString &date, const QString &subject, const QString &content, const bool sortedByDate);
    void setMailsDateIntervalCPPSlot(const QString &since, const QString &to);

    void sortByDateCPPSlot();
    void sortBySenderCPPSlot();

    void searchByQueryCPPSlot(const QString &query);
    void searchBySenderCPPSlot(const QString &sender);

    void deleteMailCPPSlot(const int id, const bool sortedByDate);


signals:
    void clearListCPPSignal();
    void clearShowMailCPPSignal();
    void addItemToListViewCPPSignal(QVariant id, QVariant from, QVariant to,
                               QVariant date, QVariant subject, QVariant content, QVariant isRead);
};

#endif // HANDLER_H
