#include "email.h"

email &email::operator = (const email &c) {
    id = c.id;
    from = c.from;
    to = c.to;
    date = c.date;
    subject = c.subject;
    content = c.content;
}
