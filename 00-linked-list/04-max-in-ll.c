#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN INT_MIN
#define MAX INT_MAX

struct node
{
    int data;
    struct node *next;
}*first; 

void create(int A[] , int n);
void display(void);
void display_recursive(struct node *p);
void sum_of_nodes(struct node *p);
void print_new_line(void);
void find_max(struct node *p);
void find_min(struct node *p);

int main(void)
{

 int A[] = {100,5,7,0,8,10}; 
 
 create(A , 6);

 display();
 print_new_line();
 display_recursive(first);
 print_new_line();
 sum_of_nodes(first);
 find_max(first);

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
    if(p != NULL)
    {
        printf("%d " , p->data);
        display_recursive(p->next);
    }
}

void sum_of_nodes(struct node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum = p->data + sum;
        p = p->next;
    }
    printf("sum of the all nodes data = %d\n" , sum);

}

void find_max(struct node *p)
{    
    int max_data = MIN;

    while (p != NULL)
    {
        if(p->data > max_data)
        {
            max_data = p->data; 
        }
        p = p->next;        
    }
    printf("Max data = %d" , max_data);
}

void find_min(struct node *p)
{    
    int min_data = MIN;
    while (p != NULL)
    {
        if(p->data > min_data)
        {
            min_data = p->data; 
        }
        p = p->next;        
    }
    printf("Min data = %d" , min_data);
}

void print_new_line(void)
{
    puts("\n====================\n");
}