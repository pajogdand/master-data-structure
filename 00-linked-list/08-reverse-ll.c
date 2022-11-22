#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
        printf("Element is first element\n");        
        first = t;
        last  = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void reverse_ll(struct node *p)
{
    if(p == NULL)
    {
        puts("list is empty");
        exit(-1);
    }
    else
    {
        struct node *q    = NULL;
        struct node *r    = NULL;
        struct node *p    = first;
        
        while (p!=NULL)
        {
            r = q;
            q = p;                      
            p = p->next;
            q->next = r;
        }
        first = q;

    }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d " ,p->data);
        p = p->next;
    }
    puts("\n");
}

int main()
{
    int size = 5;
    int A[5] = {100,3,4,5,10};

    for(int i=0;i<size ;i++)
    {
        insert(A[i]);
    }

    display(first);
    reverse_ll(first);
    display(first);

    exit(0);
}