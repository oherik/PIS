#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */
QueuePtr head;

/*
 * New queue. Skapar en ny kö, det vill säga läser in startvärden till köns HEAD.
 */
QueuePtr new_queue() {
    head->prio = MAX_PRIO;
    head->data = NULL;
    head->next=NULL;
    return head;
};

/*
 * Inserts an element after another
 */
void insert(QueuePtr q_before, QueuePtr q_after){
    q_after->next=q_before->next;
    q_before->next=q_after;
}

/*
 * Adds a new element to the queue
 */
void add(QueuePtr q, int prio, DataPtr d) {
    QueuePtr new_element = malloc(sizeof new_element);
    new_element->prio = prio;
    new_element->data = d;
    QueuePtr other = q;     //The head of the other queue
    while (1) {
        if (other->prio >= prio && other->next != NULL) {
            other = other->next;
        } else {
            insert(other, new_element);
            return;
        }
    }
};

/*
 * Returns the first data value. q is the head of the queue.
 */
DataPtr get_first(QueuePtr q){
    if(!q->next){
        return NULL;
    } else{
        return q->next->data;
    }
};

/*
 * Returns the length of the queue. q is the head of the queue.
 */
int size(QueuePtr q){
    int length = 0;
    QueuePtr other = q;
    while(other->next){
        ++length;
    }
    return length;

}

