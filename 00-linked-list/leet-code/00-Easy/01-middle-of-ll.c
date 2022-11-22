#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
}*first;

void create(int A[] , int n);
void display(void);
int covert_to_bin_number(struct node *p);
struct node *middle_of_ll(struct node *q);
int main()
{

 int data = 10;
 int *p_data = &data ;
 printf("Eaton = %llu \n" , *p_data++);

 int A[] = {1,2,3,4};
 
 int size = sizeof(A) / sizeof(int);

 create(A ,size );

 display();
 struct node *r = NULL;
 r = middle_of_ll(first);
 printf( "middle element is : %d" , r->data );

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

    while(t != NULL)
    {
        printf("data = %d " , t->data);
        t = t->next;
    }

    printf("\n");
}

int covert_to_bin_number(struct node *p)
{
    if(p == NULL)
    {
        printf("list is empty");
        return -1;
    }
    int num = 0;
    while(p!=NULL)
    {
        printf(" %d " , p->data);
        num =  (num << 1) | p->data;
        p = p->next;
    }
    return num;
}

struct node *middle_of_ll(struct node *q)
{
    
    struct node *p=q;
    
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    
    p = q;
    for(int i = 0; i<=(count/2) -1 ; i++)
    {
        p = p->next;
    }
    return p;
}