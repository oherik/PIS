#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */
/* new_queue(), add(), size(), get_first() */ 
// typedef struct QueueElement *QueuePtr;

QueuePtr new_queue()                        // Skapar en ny (tom) kö
{                      
    QueuePtr startOfList = (QueuePtr)malloc(sizeof(struct QueueElement));  
    startOfList -> prio = MAX_PRIO;
    startOfList -> data = NULL;
    startOfList -> next = NULL;
    return startOfList;
}

int  size(QueuePtr q)                         // räknar köns aktuella längd
{                    
    int length = 0;
    while (q->next) {
        length=length+1;
        q = q->next;
    }
    return length;
}

void add(QueuePtr q, int prio, DataPtr d)	 // lägger in d på rätt plats
{ 
    QueuePtr node = (QueuePtr)malloc(sizeof(struct QueueElement));
    node -> prio = prio;
    node -> data = d;
     
    while (q->next && q->next->prio >= prio) { //större än eller lika med?????
        q = q->next;
    }
    node->next = q->next;
    q->next = node;     
}

DataPtr get_first(QueuePtr q)	           // avläser första dataelementet
{         
    //kolla ifall den finns, kolla om head pekar på null eller inte
    if (!q->next) {
        return NULL;
    }else{
        return q->next->data; //måste man definiera firstData???????
    }
}

void remove_first(QueuePtr q)	           // tar bort första köelement
{   
    QueuePtr firstElement = q->next;
    if(firstElement){
        q->next = firstElement->next;  //if the first element is not null then point to the second element instead of the first.  
        free(firstElement);            //take away the memory of the first element. 
    }
}
/*
 * void delete_queue(QueuePtr q)              // tar bort kön helt och hållet
{             
    QueuePtr current_node;
     while(q){
         current_node = q;
         q = q->next;
         current_node->next = NULL;
         free(current_node);
     }
}
 * 
 * */
void internal_clear(QueuePtr q){
     QueuePtr current_node;
     while(q){
         current_node = q;
         q = q->next;
         current_node->next = NULL;
         free(current_node);
     }
 }

/**
 * @brief   Removes the queue's elements but keeps the queue itself
 * @param   q   The head of the queue
 */
 void clear(QueuePtr q){
     internal_clear(q->next);
     q->next=NULL;
 }
 
 /**
  * @brief Removes the queue
  * @param q    The head of the queue
  */
 void delete_queue(QueuePtr q){
    internal_clear(q);
 }

/*


void clear(QueuePtr q)                    // tar bort köelementen men behåller kön
{                   
    QueuePtr current_node;
    QueuePtr qNext = q->next;
     while(qNext){
         current_node = qNext;
         qNext = qNext->next;
         current_node->next = NULL;
         free(current_node);
     }
}
*/