#include<stdio.h>
#define SWAP(x,y,t)(t=x,x=y,y=t)
void selection_sort(int a[10],int n)
{   
    int i,j,min,temp,t;
    for(i=0;i<n-1;i++)
     {
        min=i;
        for(j=i+1;j<n;j++)
        {
             if(a[j]>a[min])
              min=j;
        }
        if(i!=min)
          SWAP(a[i],a[min],t);
        
     }
}

void bubble_sort(int a[10],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                SWAP(a[j],a[j+1],temp);
            }
        }
    }
}

void insertion_sort(int a[10],int n)
{  
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i;
        printf("\n");
        while(j>0)
        {   
            if(temp>a[--j])
              {
                  a[j+1]=a[j];
                  a[j]=temp;
              }
        }
    }
}
void main()
{
    int a[10],n,i,ch;
    printf("\n\tSorting\n\n");
    printf("Enter the no. of Elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
     for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("\n Select one:\n 1.Selection Sort\n 2.Bubble Sort\n 3.Insertion Sort\n\n ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:selection_sort(a,n);
                break;
        case 2:bubble_sort(a,n);
                break;
        case 3:insertion_sort(a,n);
                break;
        default:printf("\n Wrong Choice!!");
    }
     
     printf("Sorted Array:");
     for(i=0;i<n;i++)
      printf("%d ",a[i]);
    
}