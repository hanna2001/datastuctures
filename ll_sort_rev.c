#include<stdio.h>
#include<stdlib.h>


struct node* creat_new_node();
void insert();
void delete();
void display();
void reverse();

struct node{
    int data;
    struct node *link;
}*head=NULL;


void main(){
    int ch=0;
    while(ch!=6)
    {
        printf("\nSelect \n 1)Insert\n 2)Delete\n 3)Display\n 4)Sort\n 5)Reverse\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 3:display(head);
                    break;
            // case 2 :if(head==NULL)
            //             printf("\n UnderFlow");
            //         else
            //             delete();
            case 4:reverse();
                    break;
            
        }
    }
}

void insert()
{
    struct node *newNode=creat_new_node(),*temp=head,*prev=head;
    if(head==NULL)
      head=newNode;
    else
    {
      while(temp!=NULL && newNode->data>temp->data)
        {
            prev=temp;
            temp=temp->link;
        }
        if(temp==NULL)
         prev->link=newNode;
        else if(temp==head)
        {
            newNode->link=head;
            head=newNode;
        }
        else
         {
             newNode->link=prev->link;
             prev->link=newNode;
             
         }
        
    }
       
    
}

void display(struct node *head)
{
    struct node *temp=head;
    if(head==NULL)
      printf("\n Empty");
    else
     while(temp!=NULL)
     {
         printf("%d",temp->data);
         temp=temp->link;
     }
    
}

struct node* creat_new_node()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter value");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}

void reverse()
{
    struct node *prev=NULL,*next=NULL,*temp=head;
    while(temp!=NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}