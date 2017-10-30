#include "email.h"

email &email::operator = (const email &c) {
    id = c.id;
    from = c.from;
    to = c.to;
    date = c.date;
    subject = c.subject;
    content = c.content;
}

unsigned long email::getDateScore() {
    return date[0]*10000000 + date[1]*1000000 + date[2]*100000 + date[3]*10000 + date[5]*1000 + date[6]*100 + date[8]*10 + date[9];
}
