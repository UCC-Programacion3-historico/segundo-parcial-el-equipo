#include "handler.h"

Handler::Handler(QObject *parent) :
    QObject(parent)
{
}

void Handler::addNewMail(email m) {

    m.isRead = false;
    mailManager.addMail(m);
}

void Handler::updateListView() {

    emit clearListCPPSignal();

    for (int i=0; i < mailListToRender.size(); i++) {
        emit addItemToListViewCPPSignal(
                        QVariant::fromValue(mailListToRender[i].id),
                        QString::fromStdString(mailListToRender[i].from),
                        QString::fromStdString(mailListToRender[i].to),
                        QString::fromStdString(mailListToRender[i].date),
                        QString::fromStdString(mailListToRender[i].subject),
                        QString::fromStdString(mailListToRender[i].content),
                        mailListToRender[i].isRead
                    );
    }
}

void Handler::addNewMailCPPSlot(const QString &from, const QString &to, const QString &date,
                             const QString &subject, const QString &content, const bool sortedByDate) {

    email toAdd;
    toAdd.from = from.toStdString();
    toAdd.to = to.toStdString();
    toAdd.date = date.toStdString();
    toAdd.subject = subject.toStdString();
    toAdd.content = content.toStdString();
    toAdd.id = count++;

    addNewMail(toAdd);

    if (sortedByDate) mailListToRender = mailManager.getSortedByDate();
    else mailListToRender = mailManager.getSortedByFrom();

    updateListView();
}
