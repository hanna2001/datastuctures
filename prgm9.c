#include<stdio.h>
#include<ctype.h>
#include<string.h>
char infix[50],Stack[35],prefix[50];
int top=-1,p_tp=-1;

char s_pop()
{  
    char item=Stack[top];
    top--;
    return item;
}
void s_push(char n)
{
    Stack[++top]=n;
}
char p_pop()
{  
    char item=prefix[p_tp];
    p_tp--;
    return item;
}
void p_push(char n)
{
    prefix[++p_tp]=n;
}

int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 2;
    case '^':return 3;
    case ')':return 0;
    // default:printf("\n Invalid Operator!! %c\n",op);
    //         break;
    }
}

void operator_assign(char op)
{
   int n_p,o_p;
   n_p=get_precedence(op);
   o_p=get_precedence(Stack[top]);
   //printf("\n %d %d %c  ",n_p,o_p,op);
   
   if(n_p>=o_p && op!='^')
    s_push(op);
   else 
    {
      while(n_p<o_p)
      {
        p_push(s_pop());
        o_p=get_precedence(Stack[top]);
        
        if(top==-1)
          break;
      }
      s_push(op);
      }
    //printf(" %d %d %c\n",n_p,o_p,st[t]);
}

void pop_out_para(int t,int pos,char* st)
{
    int i;
    //printf("\n out %d %d ",t,pos);
    for(i=t;i>pos;i--)
      {//printf("%c",*(st+i));
      prefix[++p_tp]=*(st+i);}
      
    
}

void main()
{
    int i,j,l;
    
    printf("\n Enter the infix expression:");
    scanf("%s",infix);
    l=strlen(infix);
    if(isalnum(infix[l-1])||infix[l-1]==')')
     {
      for(i=l-1;i>=0;i--)
     {
        if(isalnum(infix[i]))
          {//printf("%c",infix[i]);
           p_push(infix[i]);}
        else
        {
            
            if(top==-1)
               s_push(infix[i]);
            else
               {if(infix[i]==')')
                  s_push(infix[i]);
                 else 
                 if(infix[i]=='(')
                  {
                   for(j=top;j>=0;j--)
                     if(Stack[j]==')')
                     {   pop_out_para(top,j,Stack);
                        top=j-1;
                        break;
                     }
                     
                 }
                 else
                    operator_assign(infix[i]);
           }
        }
    }

    for(i=top;i>=0;i--)
        prefix[++p_tp]=Stack[i];
    printf("\n Prefix Expression:");
    for(i=p_tp;i>=0;i--)
       printf("%c",prefix[i]);
     }
     else
        printf("\n Invalid Expression");
     
}