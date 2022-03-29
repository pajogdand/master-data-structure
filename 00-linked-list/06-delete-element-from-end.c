
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

void insert(int data)
{
    struct node * t =(struct node *)malloc(sizeof(struct node));
    struct node * last;

    t->data = data;
    t->next = NULL;
    
    if(first == NULL)
    {
        printf("Element is first element");        
        first = t;
        last  = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void display(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d " , p->data);
        p = p->next;       
    }
}

int main(void)
{
    int data;

    first = NULL;
    int Array[5] = {1,2,3,4,5};

    for(int i=0;i<5;i++)
    {
        insert(Array[i]);
    }

    display(first);
    
}