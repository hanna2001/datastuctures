#include <stdio.h>

#define COMPARE(x,y)(x==y?0:(x<y?1:-1))
int binary_search(int a[10],int l,int ele)
{
    int beg,end,mid,i=1,flag=0;
    beg=0;end=l-1;
    while(i)
    {
        mid=(beg+end)/2;
        switch(COMPARE(ele,a[mid]))
        {
            case 0:i=0;
                   flag=1;
                   break;
            case 1:end=mid-1;
                     break;
            case -1:beg=mid+1;
                     break;
        }
        if(beg>end)
          i=0;
    }
    if(flag==1)
      return mid;
    else
      return -1;
}
int linear_search(int a[],int l,int ele)
{
    int i,j,flag=0;
    for(i=0;i<l;i++)
     if(a[i]==ele)
          {
              flag=1;
              break;
          }
    if(flag==1)
      return i;
    else 
      return -1;
}
void main()
{
    int n,i,ele,pos,ch;
    printf("\n Select one:\n 1.Binary Search\n 2.Linear search\n ");
    scanf("%d",&ch);
    if(ch==1 || ch==2)
    {
    printf("\n Enter the no. of elements:");
    scanf("%d",&n);
    int a[n];
    if(ch==1)
    printf("\n Enter the elements in ascending order:");
    else if(ch==2)
    printf("\n Enter the elements:");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    printf("Enter the element to be searched:");
    scanf("%d",&ele);
    switch(ch)
    {
        case 1:pos=binary_search(a,n,ele);
                break;
        case 2:pos=linear_search(a,n,ele);
                break;
        default:printf("\n Wrong Choice!!");
    }
    
    if(pos==-1)
     printf("\nElement not found!!!");
    else 
     printf("\nElement found at position %d ",pos+1);
    }
}
