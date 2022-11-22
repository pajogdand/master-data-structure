#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
}*first=NULL, *second=NULL, *third=NULL;

typedef struct node * node_ptr;
void create(int *p ,int size)
{
    node_ptr last;
    for(int i=0 ; i< size ;i++)
    {
        struct node * t =(struct node *) malloc(sizeof(struct node));
        
        t->data = p[i];
        t->next = NULL;
        
        if(first == NULL)
        {
            puts("This is first node");
            first = last = t;
        }
        else
        {
             last->next = t;
             last = t;
            
        }
    }

}

void create2(int *p ,int size)
{
    node_ptr last;
    for(int i=0 ; i< size ;i++)
    {
        struct node * t =(struct node *) malloc(sizeof(struct node));
        
        t->data = p[i];
        t->next = NULL;
        
        if(second == NULL)
        {
            puts("This is first node");
            second = last = t;
        }
        else
        {
             last->next = t;
             last = t;            
        }
    }

}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d " ,p->data);
        p = p->next;
    }
    printf("\n");
}

void concat_ll(node_ptr p)
{
    node_ptr q = NULL;
    while (p != NULL)
    { 
        q = p;
        p = p->next;
    }
    q->next = second;    

}

int main()
{
    int size = 5;
    int A[5] = {100,3,4,5,10};
    int B[5] = {500,600,800, 600,1000};

    //first1 = NULL;
    create(A , size);
    create2(B , size);
    printf("first list is :");
    display(first);
    printf("second list is:");
    display(second);
    printf("concanitated list is:");
    concat_ll(first);

    display(first);    
    exit(0);
}