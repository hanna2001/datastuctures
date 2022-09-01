#include<stdio.h>
const int SIZE=5;
int DQ[5];
int front=-1,rear=-1;
void insert_at_rear()
{
    int ele;
    printf("\n Enter the element to be added:");
    scanf("%d",&ele);
    if(front==-1)
      front=rear=0;
    else if(rear==SIZE-1)
      rear=0;
    else
      rear++;
    DQ[rear]=ele;
}
void insert_at_front()
{
    int ele;
    printf("\n Enter the element to be added:");
    scanf("%d",&ele);
    if(front==-1)
      front=rear=0;
    else
      if(front==0)
       front=SIZE-1;
      else
       front--;
    DQ[front]=ele;
}
void delete_at_rear()
{
          printf("\n Element %d is deleted from rear\n ",DQ[rear]);
          if(rear==front)
            rear=front=-1;
          else if(rear==0)
           rear=SIZE-1;
          else
            rear--;
}
void delete_at_front()
{
          printf("\n Element %d is deleted from front\n ",DQ[front]);
          if(rear==front)
            rear=front=-1;
          else if(front==SIZE-1)
            front=0;
          else
            front++;
}
void display()
{
    int i;
    if(front==-1)
      printf("\n Queue is Empty!!!\n");
    else
      { 
          printf("\n Elements in Queue \n  front ");
          if(front<=rear)
            for(i=front;i<=rear;i++)
               printf(" %d ",DQ[i]);
          else
            {
             for(i=front;i<SIZE;i++)
               printf(" %d ",DQ[i]);
             for(i=0;i<=rear;i++)
               printf(" %d ",DQ[i]);
            }
               
          printf(" rear \n");
        }
}
void input_res_dq()
{
    int ch2=0,ch3;
    while(ch2!=4)
    {
        printf("\n Select an operation: \n  1.Enqueue(at rear)\n  2.Dequeue\n  3.Display\n  4.Quit\n ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1:if(((rear==SIZE-1) && front==0)||(front==rear+1))
                    printf("\n OverFlow!!\n\n");
                   else
                    insert_at_rear();
                   display();
                   break;
            case 2:if(front==-1)
                      printf("\n UnderFlow!!\n\n");
                   else
                   {
                     printf("\n Deletion at\n 1.at rear\n 2.at front\n ");
                     scanf("%d",&ch3);
                     switch (ch3)
                     {
                       case 1:
                           delete_at_rear();
                           break;
                        case 2:
                           delete_at_front();
                           break;
                        default:printf("\n Wrong choice!!\n");
                       break;
                     }
                    }
                     display();
                   break;
            case 3:display();
                   break;
            case 4: printf("\n Quitting...!");
                break;
            default: printf("\n Wrong Choice...!!\n");
                break;
        }
    }
}
void output_res_dq()
{
    int ch2=0,ch3;
    while(ch2!=4)
    {
        printf("\n Select an operation: \n  1.Enqueue\n  2.Dequeue(at front)\n  3.Display\n  4.Quit\n ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1:if(((rear==SIZE-1) && front==0)||(front==rear+1))
                     printf("\n OverFlow!!\n\n");
                   else
                   {
                     printf("\n Enqueue at\n 1.at rear\n 2.at front\n ");
                     scanf("%d",&ch3);
                     switch (ch3)
                     {
                       case 1:
                           insert_at_rear();
                           break;
                        case 2:
                           insert_at_front();
                           break;
                        default:printf("\n Wrong choice!!\n");
                       break;
                     }
                    }
                    display();
                    break;
            case 2:if(front==-1)
                      printf("\n UnderFlow!!\n\n");
                   else
                      delete_at_front();
                   display();
                   break;
            case 3:display();
                   break;
            case 4: printf("\n Quitting...!");
                break;
            default: printf("\n Wrong Choice...!!\n");
                break;
          }
    }
}
void main()
{
    int ch1;
    printf("\n Deque\n -----\n Select a Duque:\n  1.Input Restricted Deque\n  2.Output Restricted Deque\n ");
    scanf("%d",&ch1);
    switch(ch1)
    {
        case 1: input_res_dq();
                break;
        case 2: output_res_dq();
                break;
        default: printf("\n Wrong Choice!!");
    }
}