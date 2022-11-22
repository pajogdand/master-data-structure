
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
        //Element is first element
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
    printf("\n");
}

int delete_element_from_end(struct node *p)
{
    struct node *q = NULL;
    struct node *r = NULL;
    
    while(p!=NULL)
    {
        r = q;
        q = p;
        p=p->next;
    }

    r->next =NULL;
    
    int melelya_data= q->data;
    free(q);

    return melelya_data;
}

int delete_at_given_pos(struct node *p, int pos , int size)
{
    struct node *q = NULL;
    struct node *r = NULL;
    
    for(int i=0;i<size;i++)
    {
        r = q;
        q = p;
        p=p->next;
        if(i == pos)
            break;
    }

    r->next = p;
    
    int melelya_data = q->data;
    free(q);

    return melelya_data;
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
    printf("the delteted data = %d\n" , delete_element_from_end(first));
    display(first);
    printf("the delteted data = %d\n" , delete_at_given_pos(first,0,4));
    display(first);   

    exit(0);  
}