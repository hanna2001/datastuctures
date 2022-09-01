#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int pow;
    struct node *next;
}*ptr,*newNode;
void create_new_node(int pow,int coef)
{
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->pow=pow;
    newNode->coef=coef;
    newNode->next=NULL;
}
void add_new_node(struct node *p,int pow,int coef)
{
    create_new_node(pow,coef);
    // if(newNode->coef!=0)
    // {
    //     if(p==1)
    //     {
    //         newNode->next=pol1h;
    //         pol1h=newNode;
    //     }
    //     if(p==2)
    //     {
    //         newNode->next=pol2h;
    //         pol2h=newNode;
    //     }
    // }
    struct node *temp;
    temp=p;
    newNode->next=p;
    p=newNode;

}
void display(struct node* ptr)
{
    //ptr=pol1h;
    printf("%dx^%d",ptr->coef,ptr->pow);
    ptr=ptr->next;
    while(ptr!=NULL)
    {
        if(ptr->coef >0)
          printf("+%dx^%d",ptr->coef,ptr->pow);
        else
          printf("%dx^%d",ptr->coef,ptr->pow);
        ptr=ptr->next;
    }
}
void main()
{
    int deg1,deg2,i,coef;
    struct node *pol1h,*pol2h,*resh;
    printf("\n Enter the degree of 1st polynomial:");
    scanf("%d",&deg1);
    printf("\n Enter the 1st polynomial:");
    for(i=0;i<=deg1;i++)
    { 
      printf("\n Enter coefficient x^%d:",i);
      scanf("%d",&coef);
      add_new_node(pol1h,i,coef);
    }
    
    // printf("\n Enter the degree of 2nd polynomial:");
    // scanf("%d",&deg2);
    // printf("\n Enter the 2nd polynomial:");
    // for(i=0;i<=deg2;i++)
    // { 
    //   printf("\n Enter coefficient x^%d:",i);
    //   scanf("%d",&coef);
    //   add_new_node(2,i,coef);
    // }
    
    printf("\n Polynomial 1:");display(pol1h);
    //printf("\n Polynomial 2:");display(pol2h);
    //multiply();
    //printf("\n Result:");display(resh);

}
