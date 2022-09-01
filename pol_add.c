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
      printf("Zero Polynomial");
    else{
        while(ptr!=NULL){
    
             if(ptr!=head&&ptr->coef>0)
                    printf("+");
                        
            printf("%dx^%d",ptr->coef,ptr->pow);
            ptr=ptr->next;
        }
    }
}
void add(struct node *head1,struct node *head2)
{
    struct node *ptr1,*ptr2,*addh=NULL;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->pow==ptr2->pow)
        {
            addh=add_node(ptr1->coef+ptr2->coef,ptr1->pow,addh);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else
        
            if(ptr1->pow > ptr2->pow)
            {
                addh=add_node(ptr1->coef,ptr1->pow,addh);
                ptr1=ptr1->next;
            }
            else
            {
                addh=add_node(ptr2->coef,ptr2->pow,addh);
                ptr2=ptr2->next;
            }
            
        
    }
    if(ptr1!=NULL || ptr2!=NULL)
      {  struct node *rep;
         rep=ptr1?ptr1:ptr2;
        while(rep!=NULL)
        {
            addh=add_node(rep->coef,rep->pow,addh);
            rep=rep->next;
        }
      }
    // while(ptr1!=NULL){
             
    //                   addh=add_node(ptr1->coef,ptr1->pow,addh);
    //             ptr1=ptr1->next;
                    
    //         }
    //         while(ptr2!=NULL){
                
    //             addh=add_node(ptr1->coef,ptr1->pow,addh);
    //             ptr1=ptr1->next;
    //         }
    printf("\n Sum:");display(addh);
    
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
    add(pol1h,pol2h);
}