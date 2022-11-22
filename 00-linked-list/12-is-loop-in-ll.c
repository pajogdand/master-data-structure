#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
}*first = NULL;

void create(int *p , int szie);
int is_loop(struct node *f);
void display(struct node *p);

int main(void)
{
    struct node *t1 ,*t2;
    int size = 5;
    int A[5] ={1,2,3,5,6};
    create(A , size);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    if(is_loop(first))
    {
        puts("there is a loop");
    }
    else
    {
        puts("there is not loop");
    }

    exit(-1);
}

void create(int *p, int size)
{

    if(first == NULL)
    {
        puts("list is empty");
    }    
    
    for(int i = 0;i<size ; i++)
    {
        struct node *t, *last;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = p[i];
        t->next = NULL;
        if(i == 0 )
        {
            first  = last = t;
        }
        else{
            last->next = t;
            last = t;
        }
    }

}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int is_loop(struct node * f)
{
  struct node * q , *p;
  p = q = f;

  do
  {
      p = p->next;
      q = q->next;
      //q=q?q->next:q;
      if(q != NULL)
      {
          q = q->next;
      }
      else
      {
          q = q;
      }
  } while (p && q && p!=q);
  
  if( p == q )
  {
      return 1;
  }
  else
  {
      return 0;
  }
}