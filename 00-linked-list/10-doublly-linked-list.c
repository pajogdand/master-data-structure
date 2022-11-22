#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
    struct node *prv;
} *first = NULL;



void create_dll(int *p, int size)
{
    struct node * last = NULL;   
    
    for(int i=0;i<size;i++)
    {   
        if(i == 0)
        {
            struct node *first = (struct node* )malloc(sizeof(struct node));
            first->data = p[i];
            first->prv  = NULL;
            first->next = NULL;
            last = first;
        }
        else
        {
            struct node *t = (struct node* )malloc(sizeof(struct node));
            t->data = p[i];
            t->next = last->next;
            t->prv  = last;        
            last->next = t;
            last = t; 
        }   
    }
}

void display_dll(struct node *p)
{
    if(p = NULL)
    {
        printf("list is empty");
        exit(-1);
    }
    else
    {
        while(p)
        {
            printf(" %d " , p->data );    
            p = p->next;
        }
        printf("\n");

    }
}

int main()
{
    int size = 5;
    int A[5] = {10,20,30,50,60};

    create_dll(A , size);
    display_dll(first);

    exit(0);
}
