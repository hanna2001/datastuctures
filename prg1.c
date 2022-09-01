#include <stdio.h>

void dis_pol(float a[],int deg)
{
    int i;
    printf("%0.1fx^%d",a[deg],deg);  
    for(i=deg-1;i>=0;i--)
       if(a[i]>=0)
        printf(" +%0.1fx^%d",a[i],i);
       else
        printf(" %0.1fx^%d",a[i],i);
}

void main()
{
    int deg1,deg2,i,hdeg,ldeg;
    printf("Enter the degree of polynomial 1:");
    scanf("%d",&deg1);
    float pol1[deg1+1];
    for(i=0;i<=deg1;i++)
    {
        printf("  Enter the coefficient of x^%d:",i);
        scanf("%f",&pol1[i]);
    }
    printf("\nEnter the degree of polynomial 2:");
    scanf("%d",&deg2);
    float pol2[deg2+1];
    for(i=0;i<=deg2;i++)
    {
        printf("  Enter the coefficient of x^%d:",i);
        scanf("%f",&pol2[i]);
    }
    if(deg1==deg2)
     hdeg=ldeg=deg2;
    else
    {
        hdeg=(deg1>deg2)?deg1:deg2;
        ldeg=(deg1<deg2)?deg1:deg2;
    }
    float sum[hdeg+1];
    for(i=0;i<=ldeg;i++)
    {
        sum[i]=pol1[i]+pol2[i];
    }
    if(!(hdeg==ldeg))
    {
        if(deg2==hdeg)
            for(;i<=hdeg;i++)
                sum[i]=pol2[i];
        else
            for(;i<=hdeg;i++)
                sum[i]=pol1[i];
    }
    printf("\nPolynomial 1:");
    dis_pol(pol1,deg1);
    printf("\nPolynomial 2:");
    dis_pol(pol2,deg2);
    printf("\n\n  Sum       :");
    dis_pol(sum,hdeg);
}