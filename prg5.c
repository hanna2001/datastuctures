#include<stdio.h>
const int size=5;
int top=-1;
void push(int *st)
{
    if(top>=size-1)
      printf("\n Stack Overflow!! No more Elements can be added \n!!");
    else
      {
          int ele;
          printf("\n Enter the element to be inserted:");
          scanf("%d",&ele);
          ++top;
          *(st+top)=ele;
          printf("\n The element %d is inserted at position %d\n",ele,top );
          
      }
}
void display(int *st)
{
    if(top==-1)
      printf("Stack is Empty!!");
    else
    {
        printf("\n Elements in the Stack:");
        for(int i=top;i>=0;i--)
        printf("\n  %d  ",*(st+i));
    }
}
void pop(int *st)
{
	if(top==-1)
        printf("\n No more Elements can be deleted!! Underflow!!\n");
	else
	{
		int ele= *(st+top);
		printf("\n The element %d is deleted from position %d\n",ele,top );
		top--;
        
    }
}
void main()
{
    int Stack[10],input=0;
    while(input!=4)
    {
        printf("\n Stack Operations:\n 1.Add element(Push)\n 2.Delete element(Pop)\n 3.Display\n 4.Quit\n");
        scanf("%d",&input);
        switch (input)
        {
         case 1: push(Stack);
                 display(Stack);
                break;
         case 2: pop(Stack);
                 display(Stack);
                break;
         case 3: display(Stack);
                break;
         case 4: printf("\n Quitting...!");
                break;
         default: printf("\n Wrong Choice...!!\n");
                break;
        }
    }
}

// #include<stdio.h>
// const int size=10;
// int push(int *st,int ele,int top)
// {
//     if(top>size)
//       {
//           printf("\n Stack is full!! No more can be added !!");
//           return top--;
//       }
//     else
//       {
//           *(st+top)=ele;
//           printf("\n The element %d is inserted at position %d\n",ele,top );
//           return top;
//       }
// }
// void display(int *st,int top)
// {
//     printf("Element in the Stack:");
//     for(int i=top;i>=0;i--)
//      printf("\n  %d  ",*(st+i));
// }
// int pop(int *st,int top)
// {
// 	if(top==-1)
//     {
//         printf("\n No more Elements can be deleted!! Underflow!!");
//         return top;
//     }
// 	else
// 	{
// 		int ele= *(st+top);
// 		printf("\n The element %d is deleted from position %d\n",ele,top );
// 		top--;
//         return top;
//     }
// }
// void main()
// {
//     int Stack[10],elem=0,top=-1,input=0;
//     while(input!=4)
//     {
//         printf("\n Stack Operations:\n 1.Add element(Push)\n 2.Delete element(Pop)\n 3.Display\n 4.Quit\n");
//         scanf("%d",&input);
//         switch (input)
//         {
//         case 1: printf("\n Enter the element to be inserted:");
//                 scanf("%d",&elem);
//                 top=push(Stack,elem,++top);
//                 break;
//         case 2: top=pop(Stack,top);
//                 break;
//         case 3: display(Stack,top);
//                 break;
//         case 4: printf("\n Quitting");
//                 break;
//         default: printf("\n Wrong Choice");
//                 break;
//         }
//     }
// }