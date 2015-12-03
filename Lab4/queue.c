#include "queue.h"
#include <stdlib.h>

/*
 * New queue. Creates a new queue with a head element. Returns the head pointer.  
 */
QueuePtr new_queue() {
    QueuePtr head =  malloc(sizeof head);   // Allocates memory for the head
    head->prio = MAX_PRIO;
    head->data = NULL;
    head->next = NULL;
    return head;                      
}

/*
 * Inserts an element after another
 */
void insert(QueuePtr q_before, QueuePtr q_after){
    q_after->next = q_before->next;
    q_before->next =q_after;
} 

/*
 * Adds a new element to the queue based on the priority. R
 */
void add(QueuePtr q, int prio, DataPtr d) {
    QueuePtr new_element = malloc(sizeof new_element);  // Allocates memory for the new element
    new_element->prio = prio;
    new_element->data = d;
    while (q->next && q->next->prio>=prio){     // If the other element has a pointer to another element and that element's priority isn't lower than the new one
        q = q->next;                            // ...step to the next element
    }
    insert(q, new_element);                         // Either the list has ended or an element with lower priority has been found. Insert the new element after the other.    
}

/*
 * Returns the first data value. q is the head of the queue.
 */
DataPtr get_first(QueuePtr q){
    if(!q->next){
        return NULL;            // No data exists
    } else{
        return q->next->data;   // Return the data of the first element (can be NULL)
    }
}

/*
 * Returns the length of the queue. q is the head of the queue.
 */
int size(QueuePtr q){
    int length = 0;
    while(q->next){         // Steps through the whole queue
        ++length;
        q = q->next;    
    }
    return length;
}

