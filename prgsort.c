// #include<stdio.h>

// void heapSort(int [],int);
// void heapify(int [],int,int);
// void swap(int*,int*);
// void mergeSort(int [],int,int);
// void merge(int [],int,int,int);
// void quickSort(int [],int,int);
// void main()
// {
//     int arr[10],n,i;
//     printf("Enter the no of elements:");
//     scanf("%d",&n);
//     printf("\n Enter elements:");

//     for(i=0;i<n;i++)
//      scanf("%d",&arr[i]);
//     //heapSort(arr,n);
//     //mergeSort(arr,0,n-1);
//     quickSort(arr,0,n);
//     for(i=0;i<n;i++)
//      printf("%d ",arr[i]);
// }
// void quickSort(int arr[],int l,int r)
// {
//     if(l>=r)
//      return;
//     int i=l+1,j=r-1,pivot=arr[l];
//     while(i<j){
//         while(arr[i]<pivot)
//             i++;
//         while(arr[j]>pivot)
//             j--;
//         if(i<j)
//             swap(&arr[i],&arr[j]);
//     }
//     if(pivot>arr[j])
//     {
//         swap(&arr[l],&arr[j]);
//     }
//     quickSort(arr,l,j);
//     quickSort(arr,j+1,r);
     
    
// }

// void mergeSort(int arr[],int l,int r)
// {
//     if(l>=r)
//      return;
//     int m=(l+r)/2;
//     mergeSort(arr,l,m);
//     mergeSort(arr,m+1,r);
//     merge(arr,l,m,r);
// }

// void merge(int arr[],int l,int m,int r)
// {
//     int temp[10],k=l,i=l,j=m+1;
//     while(i<=m && j<=r)
//     {
//         if(arr[i]<=arr[j])
//           temp[k]=arr[i++];
//         else
//           temp[k]=arr[j++];
//         k++;
          
//     }
//     while(i<=m)
//         temp[k++]=arr[i++];
//     while(j<=r)
//         temp[k++]=arr[j++];
//     for(i=l;i<k;i++)
//      arr[i]=temp[i];
    
// }

// void heapSort(int arr[],int n)
// {
//     int i;
//     for(i=(n-1)/2;i>=0;i--)
//      heapify(arr,n,i);
    
//     for(i=0;i<n-1;i++)
//     {
//         swap(&arr[n-1-i],&arr[0]);
//         heapify(arr,n-1-i,0);
//     }
// }

// void heapify(int arr[],int n,int i)
// {
//     int parent=i,rchild=2*i+2,lchild=2*i+1;
    
//     if(lchild<n && arr[lchild]>arr[parent])
//      parent=lchild;
    
//     if(rchild<n && arr[rchild]>arr[parent])
//      parent=rchild;
     
//     if(parent!=i)
//     {
//         swap(&arr[i],&arr[parent]);
//         heapify(arr,n,parent);
//     }
// }
// void swap(int *a,int *b)
// {
//     int temp=*b;
//     *b=*a;
//     *a=temp;
// }

#include<stdio.h>
int arr[10];
void mergeSort(int ,int );
void merge(int,int,int);
void quickSort(int,int);
void heapSort(int);
void heapify(int,int);
void swap(int*,int*);

void main()
{
    int i,n,ch;
    printf("\n Enter no of elements:");
    scanf("%d",&n);
    printf("\n Enter elements:");
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    printf("\n Select one:\n 1)Quick Sort\n 2)Merge Sort\n 3)Heap Sort\n\n ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:quickSort(0,n);
      break;
    case 2:mergeSort(0,n-1);
      break;
    case 3:heapSort(n);
      break;
    default:printf("\n Wrong choice..");
      break;
    }
    printf("\n\n Sorted Array:");
    for(i=0;i<n;i++)
      printf(" %d ",arr[i]);
}
void mergeSort(int lft,int rght)
{
    if(lft>=rght)
    return;
    int mid=(lft+rght)/2;
    
    mergeSort(lft,mid);
    mergeSort(mid+1,rght);
    merge(lft,mid,rght);
}
void merge(int l,int m,int r)
{
    int i=l,j=m+1,k=l,b[10];
    // for(ln=0;ln<m;ln++)//   left[ln]=arr[ln];// for (rn=0;rn<(r-m);rn++)//   right[rn]=arr[m+rn];// printf("\n Left:");// for(k=0;k<ln;k++)//   printf(" %d ",left[k]);// printf("\n Right:");// for(k=0;k<rn;k++)//   printf(" %d ",right[k]);// k=0;////ln=i-1;rn=j-1;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
            b[k]=arr[i++];
        else 
            b[k]=arr[j++];
        k++;
    }
    while(i<=m)
        {b[k++]=arr[i++];}
    
      while(j<=r)
        {b[k++]=arr[j++];}//printf("\n Merge:");
    for(i=l;i<=r;i++)
      arr[i]=b[i];

}
void heapSort(int n)
{
  int i;
  for(i=(n-1)/2;i>=0;i--)
   heapify(i,n);
  
  //swap(arr[n-1],arr[0]);
  for(i=n-1;i>=0;i--)
  {
    swap(&arr[i],&arr[0]);
    heapify(0,i-1);
  }
}
void heapify(int i,int n)
{
  int parent,lchild,rchild;//i=0
  parent=i;//0
  lchild=2*i+1;//1
  rchild=2*i+2;//2

  if(lchild<n && arr[lchild]>arr[parent])
  {
    parent=lchild;//1
  }
  if(rchild<n && arr[rchild]>arr[parent])
    parent=rchild;//2
  
  if(parent!=i)
  {
    swap(&arr[i],&arr[parent]);
    heapify(parent,n);
  }

}
void swap(int *n1,int *n2)
{
  int temp=*n1;
  *n1=*n2;
  *n2=temp;
}
void quickSort(int l,int r)
{
  if(l>=r)
   return;
  int i,j,piv;
  i=l+1;j=r-1;piv=arr[l];
  while(i<j)
  {  
    while(arr[i]<piv && i<r-1)
    {
      i++;
    }
    while(arr[j]>piv && j>=l)
    {
      j--;
    }
    if(i<j)
    {
      
      swap(&arr[i],&arr[j]);
    }
  }
  if(piv>arr[j])
  {
    swap(&arr[l],&arr[j]);
  }
  quickSort(l,j);
  quickSort(j+1,r);
}