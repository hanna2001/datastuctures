#include <stdio.h>
int enter_covert_tuple(int m,int n,int (*t)[3])
{
    int a[5][5],i,k=0,j;
    for(i=0;i<m;i++)
     for(j=0;j<n;j++)
      {
            scanf("%d",&a[i][j]);
            if(a[i][j])
            {
                *(*(t+k)+0)=i;//t[k][0]
                *(*(t+k)+1)=j;
                *(*(t+(k++))+2)=a[i][j];
            }  
      }
      return k;
}
void print_tuple(int r, int (*t_m)[3] )
{
    for(int i=0;i<r;i++)
      printf("%d\t%d\t%d\n",*(*(t_m+i)+0),*(*(t_m+i)+1),*(*(t_m+i)+2));
}   
void print_tuple_trans(int r, int (*t)[3] )
{
    int t_m[10][3],i,j,k,l;
    for(i=0;i<r;i++)
     {
         t_m[i][0]=t[i][1];
         t_m[i][1]=t[i][0];
         t_m[i][2]=t[i][2];
     }
    for(i=0;i<r-1;i++)//sorting of transpose
     {
        int min=i;
        for(j=i+1;j<r;j++)
         if((t_m[j][1]+(t_m[j][0]*10))<(t_m[min][1]+(t_m[min][0]*10)))
             min=j;
         if(i!=min)
         {
                 int templ[3]={t_m[min][0],t_m[min][1],t_m[min][2]};
                 int tempg[3]={t_m[i][0],t_m[i][1],t_m[i][2]};
                 for(k=0;k<3;k++)
                 {
                     t_m[i][k]=templ[k];
                     t_m[min][k]=tempg[k];
                 }
            }
      }
     print_tuple(r,t_m);
}
void main()
{
    int m,n,i,j,k,l,t1[25][3],t2[25][3];
    printf("Enter the no of Rows and coloums:");
    scanf("%d%d",&m,&n);
    printf("Enter elements of 1st matrix:");
    k=enter_covert_tuple(m,n,t1);
    printf("\n1st matrix in tuple form:\n");
    print_tuple(k,t1);
    printf("\n1st matrix's transpose in tuple form:\n");
    print_tuple_trans(k,t1);
    
    printf("Enter elements of 2nd matrix:");
    l=enter_covert_tuple(m,n,t2);
    printf("\n2nd matrix in tuple form:\n");
    print_tuple(l,t2);
    printf("\n2nd matrix's transpose in tuple form:\n");
    print_tuple_trans(l,t2);
    int t3[10][3],h=0;
    i=0,j=0;
    while((i<k) &&(j<l))
    {
      if((t1[i][0]==t2[j][0])&&(t1[i][1]==t2[j][1]))
      {
          t3[h][0]=t1[i][0];
          t3[h][1]=t1[i][1];
          t3[h][2]=t1[i++][2]+t2[j++][2];
      }
      else
      if(((t1[i][0])*10+(t1[i][1]))<((t2[j][0])*10+(t2[j][1])))//finding smaller index
      {
          t3[h][0]=t1[i][0];
          t3[h][1]=t1[i][1];
          t3[h][2]=t1[i++][2];
      }
      else
      {
          t3[h][0]=t2[j][0];
          t3[h][1]=t2[j][1];
          t3[h][2]=t2[j++][2];
      }
      h++;
    }
    if(i<k)//to fill the greater tuple
      while(i<k)
          {
                t3[h][0]=t1[i][0];
                t3[h][1]=t1[i][1];
                t3[h++][2]=t1[i++][2];
          }
      else
      while(j<l)
      {
          t3[h][0]=t2[j][0];
          t3[h][1]=t2[j][1];
          t3[h++][2]=t2[j++][2];
      }
    printf("\nSum of matrices in tuple form:\n");
    print_tuple(h,t3);
}