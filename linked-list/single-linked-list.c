#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node* start=NULL;
struct node* createNode()
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void insertBegining(int item)
{
  struct node*p=createNode();
  p->info=item;
  p->next=start;
  start=p;
}
void insertEnd(int item)
{
    struct node*p=createNode();
    p->info=item;
    p->next=NULL;
    if(start==NULL)
      start=p;
    else
    {
    struct node *temp=start;
    while(temp->next!=NULL)
      temp=temp->next;
    temp->next=p;
    }
}
void insertAfter(struct node *Q, int item)
{
    if(Q==NULL)
    {
      printf("LOC NOT AVAILABLE");
      exit(1);
    }
    struct node*p=createNode();
    p->info=item;
    p->next=Q->next;
    Q->next=p;
}
void Traversal()
{
    if(start!=NULL)
    {
        struct node* temp=start;
        while(temp!=NULL)
        {
            printf("%d->",temp->info);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int deleteBegining()
{
    if(start==NULL)
      printf("Underflow");
    else
    {
        int item=start->info;
        struct node*p=start;
        start=start->next;
        free(p);
        return item;
    }
}
int deleteEnd()
{
    if(start==NULL)
     printf("underflow");
    else
    {
    struct node*shadow,*current=start;
    while(current->next!=NULL)
    {
        shadow=current;
        current=current->next;
    }
    int item=current->info;
    shadow->next=NULL;
    free(current);
    return item;
    }
}
int main()
{

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);
    insertEnd(7);
    Traversal();
    int x,y;
    printf("Enter the data and node value after which you want to insert data\n");
    scanf("%d%d",&x,&y);
    struct node*temp=start;
    while(temp!=NULL)
    {
        if(temp->info==y)
          break;
        temp=temp->next;
    }
    if(temp!=NULL)
    insertAfter(temp,x);
    Traversal();
    int item=deleteBegining();
    printf("%d deleted successfully\n",item);
    Traversal();
    int item2=deleteEnd();
    printf("%d deleted successfully\n",item2);
    Traversal();
    return 0;
}