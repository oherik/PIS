#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */
QueuePtr head;

QueuePtr new_queue() {
    head->prio = MAX_PRIO;
    head->data = 0;
};