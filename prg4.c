#include<stdio.h>
const int size=5; 
int front=0,rear=0;
void enqueue(int *q)
{
    int ele;
    if(rear>=size)
      {
        printf("\nQueue is full!!\n");
      }
    else
        {
            printf("\nEnter the element to be added:");
            scanf("%d",&ele);
            if(front==0)
                rear=front=1;
            else
                rear++;
            *(q+rear)=ele;
            printf("\n The element %d is added!!\n",ele);
         }
}

void dequeue(int *q)
{
    
    if(front==0)
      printf("\n Underflow!!\n");
    else 
    {
    printf("\n The element %d is Deleted!!\n",*(q+front));
    if(front==rear)
        front=rear=0;   
    else
      front++;
    }
}

void display(int *q)
{
    int i;
    if(front==0)
      printf("\n Queue is Empty!!\n");
    else
    {
        printf("\n Elements in the Queue:\n\n front");
        for(i=front;i<=rear;i++)
           printf("\n  %d",*(q+i));
        printf("\n rear\n");
        
    }
}

void main()
{
    int Queue[5],input=0;
    while(input!=4)
    {
        printf("\n Queue Operations:\n 1.Add element(Enqueue)\n 2.Delete element(Dequeue)\n 3.Display\n 4.Quit\n");
        scanf("%d",&input);
        switch (input)
        {
         case 1: enqueue(Queue);
                 display(Queue);
                break;
         case 2: dequeue(Queue);
                 display(Queue);
                break;
         case 3: display(Queue);
                break;
         case 4: printf("\n Quitting...!");
                break;
         default: printf("\n Wrong Choice...!!\n");
                break;
        }
    }
}