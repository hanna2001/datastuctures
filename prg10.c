#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*newNode,*head=NULL;
void create_new_nod()
{
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter the element:");
  scanf("%d",&newNode->info);
  newNode->link=NULL;
}
void insert_at_beg()
{
    create_new_nod();
    if(head!=NULL)
        newNode->link=head;
     head=newNode;
}
void insert_at_end()
{   
    struct node *temp;
    if(head==NULL)
    insert_at_beg();
    else
    {
    create_new_nod();    
    temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newNode;
    }
}
void delete_at_beg()
{   struct node *temp;
    temp=head->link;
    free(head);
    head=temp;
}
void delete_at_rear()
{
    struct node *temp,*del;
    temp=head;
    if(temp->link==NULL)
     delete_at_beg();
    else
    {
        while(temp->link->link!=NULL )
       {
            temp=temp->link;
       }
        del=temp->link;
        free(del);
        temp->link=NULL;
    }
}
void delete_at_pos()
{
    struct node *temp,*prev;
    int pos,i=1;
    temp=head;
    printf("\n Enter Position:");
    scanf("%d",&pos);
    if(pos==1)
      delete_at_beg();
    else 
    {
    while(i!=pos && temp!=NULL)
     {
        prev=temp;
        temp=temp->link;
        i++;
     }
     if(i!=pos || temp==NULL)
      printf("\n Invalid Position!!\n");
     else
      {prev->link=temp->link;
      free(temp);}
    }
}
void insert_at_pos()
{
    struct node *temp;
    int pos,i=1;
    printf("\n Enter position:");
    scanf("%d",&pos);
    if(pos==1)
     insert_at_beg();
    else 
    { temp=head;
     while (temp!=NULL && i!=pos-1)
     {
        temp=temp->link;
        i++;
     }
     if(temp==NULL)
      printf(" \n Cannot find position %d\n",pos);
     else
     {
        create_new_nod();
        newNode->link=temp->link;
        temp->link=newNode;
     }  
    }
}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
      printf("\n Empty!!\n");
    else
    printf("\n Head -> ");
    while(temp=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
}
void insertion(int ch)
{
    switch (ch)
    {
    case 1:insert_at_beg(ch);
            break;
    case 2:insert_at_end(ch);
            break;
    case 3:insert_at_pos(ch);
           break;
    case 4:break;
    }
}
void deletion(int ch)
{
    switch (ch)
    {
    case 1:delete_at_beg();
            break;
    case 2:delete_at_rear();
           break;
    case 3:delete_at_pos();
           break;
    case 4:break;
    }
}

void main()
{
    int ch=0,ch2=0;
while(ch!=4)
    {
        printf("\n Select an operation: \n  1.Insertion\n  2.Deletion\n  3.Display\n  4.Quit\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Insertion at: \n  1.Beginning\n  2.End\n  3.Specific Position\n  4.Back\n ");
                   scanf("%d",&ch2);
                   insertion(ch2);
                   display();
                   break;
            case 2:if(head==NULL)
                     printf("\n Underflow!!\n");
                   else
                   {
                        printf("\n Deletion at: \n  1.Beginning\n  2.End\n  3.Intermediate Position\n  4.Back\n ");
                        scanf("%d",&ch2);
                        deletion(ch2);
                   }
                   display();
                   break;
            case 3:display();
                break;
            case 4: printf("\n Quitting...!");//display();
                break;
            default: printf("\n Wrong Choice...!!\n");
                        

        }
    }
}