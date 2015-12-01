#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */
QueuePtr head;

/*
 * New queue. Skapar en ny kö, det vill säga läser in startvärden till köns HEAD.
 */
QueuePtr new_queue() {
    head->prio = MAX_PRIO;
    head->data = 0;
};