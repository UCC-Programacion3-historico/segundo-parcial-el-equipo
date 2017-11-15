#include "handler.h"

Handler::Handler(QObject *parent) :
    QObject(parent)
{
}

void Handler::initListView() {

    emit clearListCPPSignal();
    mailListToRender = mailManager.getSortedByDate();
    updateListView();
}

void Handler::addNewMail(email m) {

    m.isRead = false;
    m.to = QString::fromStdString(m.to).toLower().toStdString();
    m.from = QString::fromStdString(m.from).toLower().toStdString();
    if (m.subject.empty()) m.subject = "(Sin asunto)";
    mailManager.addMail(m);
}

void Handler::updateListView() {

    emit clearListCPPSignal();

    for (int i=0; i < mailListToRender.size(); i++) {
        emit addItemToListViewCPPSignal(
                        (int) (mailListToRender[i].id),
                        QString::fromStdString(mailListToRender[i].from),
                        QString::fromStdString(mailListToRender[i].to),
                        QString::fromStdString(mailListToRender[i].date),
                        QString::fromStdString(mailListToRender[i].subject),
                        QString::fromStdString(mailListToRender[i].content),
                        mailListToRender[i].isRead
                    );
    }

    if (mailListToRender.size() == 0) emit clearShowMailCPPSignal();
}

void Handler::addNewMailCPPSlot(const QString &from, const QString &to, const QString &date,
                             const QString &subject, const QString &content, const bool sortedByDate) {

    email toAdd;
    toAdd.from = from.toLower().toStdString();
    toAdd.to = to.toLower().toStdString();
    toAdd.date = date.toStdString();
    toAdd.subject = subject.toStdString();
    toAdd.content = content.toStdString();

    addNewMail(toAdd);

    if (sortedByDate) mailListToRender = mailManager.getSortedByDate();
    else mailListToRender = mailManager.getSortedByFrom();

    updateListView();
}


void Handler::setMailsDateIntervalCPPSlot(const QString &since, const QString &to) {

    mailListToRender = mailManager.getSortedByDate(since.toStdString(), to.toStdString());

    updateListView();
}

void Handler::sortByDateCPPSlot() {

    mailListToRender = mailManager.getSortedByDate();
    updateListView();
}

void Handler::sortBySenderCPPSlot() {
    mailListToRender = mailManager.getSortedByFrom();
    updateListView();
}

void Handler::searchByQueryCPPSlot(const QString &query) {

    mailListToRender = mailManager.getByQuery(query.toStdString());
    updateListView();
}

void Handler::searchBySenderCPPSlot(const QString &sender) {

    mailListToRender = mailManager.getByFrom(sender.toStdString());
    updateListView();
}

void Handler::deleteMailCPPSlot(const int id, const bool sortedByDate) {

    mailManager.deleteMail((unsigned long) id);

    if (sortedByDate) mailListToRender = mailManager.getSortedByDate();
    else mailListToRender = mailManager.getSortedByFrom();

    updateListView();
}
