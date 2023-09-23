#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    //这个函数得目的为检查单向链表是否有环得算法
    node *rabbit = head;
    node *turtle = head;
    while(rabbit!=NULL)
    {
        rabbit = rabbit->next;
        if(rabbit==NULL)
        {
            return 0;
        }
        rabbit = rabbit ->next;
        if(rabbit==NULL)
        {
            return 0;
        }
        turtle = turtle->next;
        if(turtle==NULL)
        {
            return 0;
        }
        if(rabbit==turtle)
        {
            return 1;
        }

    }
    return 0;
}