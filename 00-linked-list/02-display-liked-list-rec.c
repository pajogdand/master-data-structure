
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

void create(int A[] , int n);
void display(void);
void display_recursive(struct node *p);


int main()
{

 int A[] = {100,5,7,0,8,10};
 
 create(A , 6);

 display();
 
 display_recursive(first);

 exit(0);

 
}

void create(int A[] , int n)
{
    int i;
    struct node *t,*last;
    for(i=0;i<n;i++)
    {
        if(i == 0)
        {
            // create first node
            first = (struct node *)malloc(sizeof(struct node*));
            first->data = A[i];
            first->next = NULL;
            
 
            // make last point of first node
            last  =  first;
        }
        else{
            t = (struct node *)malloc(sizeof(struct node *));
            t->data = A[i];
            t->next = NULL;

            last->next = t;
            last = t;
        }
    }
    
}

void display()
{
    struct  node *t;
    t = first;
    
    printf("display liked list without using recuresion\n");
    while(t != NULL)
    {
        printf("%d " , t->data);
        t = t->next;
    }
}

void display_recursive(struct node *p)
{
    printf("display liked list with using recuresion\n");   
    if(p != NULL)
    {
        printf("%d " , p->data);
        display_recursive(p->next);
    }
}