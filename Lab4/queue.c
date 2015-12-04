#include "queue.h"
#include <stdlib.h>

/**
 * @brief New queue. Creates a new queue with a head element. Returns the head pointer.  
 * @return  The head of the new queue
 */
QueuePtr new_queue() {
    QueuePtr head =  malloc(sizeof head);   // Allocates memory for the head
    head->prio = MAX_PRIO;
    return head;                      
}

/**
 * @brief Inserts an element after another
 * @param q_before  The first element
 * @param q_after   The element which is to be placed after the first
 */
void insert(QueuePtr q_before, QueuePtr q_after){
    q_after->next = q_before->next;
    q_before->next =q_after;
} 

/**
 * @brief Adds a new element to the queue based on the priority. 
 * @param   q   The head of the queue
 * @param   prio    The priority of the element
 * @param   d   The data pointer of the element
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

/**
 * @brief Returns the first data value. q is the head of the queue.
 * @param  q    The head of the queue
 * @return  The first data element of the queue, if it exists, NULL otherwise
 */
DataPtr get_first(QueuePtr q){
    if(!q->next){
        return NULL;            // No data exists
    } else{
        return q->next->data;   // Return the data of the first element (can be null)
    }
}

/**
 * @brief Returns the length of the queue. 
 * @param  q    The head of the queue
 */
int size(QueuePtr q){
    int length = 0;
    while(q->next){         // Steps through the whole queue
        ++length;
        q = q->next;    
    }
    return length;
}

/**
 * @brief   Removes the first queue element
 * @param q The head of the queue
 */
void remove_first(QueuePtr q){
    QueuePtr first_element = q->next;
    if(first_element){
        q->next = first_element->next;  // The first element isn't null. Set the head's next element pointer to the second element (this can be null)
        free(first_element);             // Free the first element (the data is kept intact)
    }
}