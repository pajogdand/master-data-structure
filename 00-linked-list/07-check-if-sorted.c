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

int check_if_sorted(struct node *p)
{
    if(p == NULL )
    {
        puts("list is sorted !!");
        exit(-1);
    }
    else{
        int largest = INT_MIN;
        
        while (p != NULL)
        {
            if(p->data > largest)
            {
                largest = p->data;
            }
            else
            {
                return 0;
            }
            p = p->next;
        }
        return 1;                
    }
}

int main()
{
    int size = 5;
    int A[5] = {100,3,4,5,10};

    for(int i=0;i<size ;i++)
    {
        insert(A[i]);
    }

    if( check_if_sorted(first) == 1 )
    {
        puts("list is sorted");
    }
    else{
        puts("list if not sorted");
    }
    exit(0);
}