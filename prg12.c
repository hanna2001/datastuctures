#include<stdio.h>
#include<stdlib.h>
struct node
{
   int pow;
   int coef;
   struct node *next;
}*newNode;

void create_new_node(int coef,int pow)
{
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coef=coef;
    newNode->pow=pow;
    newNode->next=NULL;
}
struct node* add_node(int coef,int pow,struct node *head)
{
    struct node *ptr;
    create_new_node(coef,pow);
        if(newNode->coef!=0)
       {
        if(head==NULL)
          head= newNode;
        else
        {ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newNode;}
       }
        return head;
}
void display(struct node *head)
{
    struct node *ptr=head;
    if(head==NULL)
      printf("No Elements");
    else{
        while(ptr!=NULL){
    
             if(ptr!=head&&ptr->coef>0)
                    printf("+");
                        
            printf("%dx^%d",ptr->coef,ptr->pow);
            ptr=ptr->next;
        }
    }
}
void delete_same_pow(struct node **resh)
{
    struct node *ptr;
    int pow;struct node *temp;
    ptr=*resh;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        while(temp->next!=NULL)
        {
            if(ptr->pow==temp->next->pow)
            
             {//printf(" YES ");
                 ptr->coef+=temp->next->coef;
                 temp->next=temp->next->next;
             }
            temp=temp->next;//printf(" yes ");
        }
        ptr=ptr->next;
    }
}
void multiply(struct node *head1,struct node *head2)
{
    struct node *ptr1,*ptr2,*resh=NULL;
    ptr1=head1;
    while(ptr1!=NULL)
    {
        ptr2=head2;
        while(ptr2!=NULL)
        {
            resh=add_node(ptr1->coef*ptr2->coef,ptr1->pow+ptr2->pow,resh);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    delete_same_pow(&resh);
    printf("\n Resultant:");display(resh);
}



void main()
{
    struct node *pol1h=NULL,*pol2h=NULL;
    int deg1,deg2,coef;
    printf("\n Enter degree of polynomial 1:");
    scanf("%d",&deg1);
    for(int i=deg1;i>=0;i--)
    {
        printf("\n Enter coefficent of x^%d:",i);
        scanf("%d",&coef);
        pol1h=add_node(coef,i,pol1h);   
    }
    
    printf("\n Enter degree of polynomial 2:");
    scanf("%d",&deg2);
    for(int i=deg2;i>=0;i--)
    {
        printf("\n Enter coefficent of x^%d:",i);
        scanf("%d",&coef);
        pol2h=add_node(coef,i,pol2h);   
    }
    printf("\n Polynomial 1:");display(pol1h);
    printf("\n Polynomial 2:");display(pol2h);
    multiply(pol1h,pol2h);
}