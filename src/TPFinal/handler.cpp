#include "handler.h"

Handler::Handler(QObject *parent) :
    QObject(parent)
{
}

void Handler::slotClear() {

    emit clearListSignal();
}
