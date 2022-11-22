#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node
{
    int data;
    struct node *next;
}*first = NULL;


void create(int *p , int size);
void display_cll(struct node *);

int main()
{
    int size = 5;
    int A[5] = {1,2,3,4,5};
    create(A, size);
    display_cll(first);
    exit(0);
}


void create(int *p , int size)
{
    struct node *last = NULL;
    for(int i=0; i<size ; i++)
    {
        
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = p[i];
        t->next = NULL;

        if(i == 0)
        {
            first = last = t;            
        }
        else{
            last->next  = t;
            last = t;
        }
    }
    last->next = first;
}

void display_cll(struct node *p)
{
    while(p->next != first)
    {
        printf(" %d " , p->data);
        p = p->next;
    }
    printf(" %d \n" ,p->data);
}