#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root,*newNode;
struct node* search(int val)
{
  struct node *temp;
  int flag=0;
  if(root==NULL)
      flag=0;
    else
    {
        temp=root;
        //parent=root;
        while(temp!=NULL && flag!=1)
        {
          if(val>temp->data)//printf("***");
            {//parent=temp;
             temp=temp->rchild;}
            else if(val<temp->data)
            {//parent=temp;
             temp=temp->lchild;}
            else flag=1;
        }
        
    }
    return temp;

}
int leaf_count(struct node *node)
{
  if(node == NULL)
    return 0;
  if(node->lchild == NULL && node->rchild == NULL)
    return 1;
  else 
    return leaf_count(node->lchild)+leaf_count(node->rchild);
  
}
void find_left_right_child()
{
    int val;
    struct node *temp;
    printf("\n Enter the element:");
    scanf("%d",&val);
    temp=search(val);
    if(temp->lchild || temp->rchild)
    {
        if(temp->rchild)
          printf("\n Right Child: %d",temp->rchild->data);
        else
          printf("\n Left Child: %d",temp->lchild->data);
    }
}
struct node* findMinimum(struct node *cur)  
{  
    while(cur->lchild != NULL) {  
        cur = cur->lchild;  
    }  
    return cur;  
} 
void delete_val(int val)
{
    struct node *temp,*parent,*ptr;
    int flag=0,a;
    if(root==NULL)
      printf("\n Underflow \n");
    else
    {
        temp=root;
        parent=root;
        while(temp!=NULL && flag!=1)
        {
          if(val>temp->data)//printf("***");
            {parent=temp;
             temp=temp->rchild;}
            else if(val<temp->data)
            {parent=temp;
             temp=temp->lchild;}
            else flag=1;
        }
        if(flag==1)
        { 
          if(temp->lchild && temp->rchild)///two child
          { 
            ptr=findMinimum(temp->rchild);
            val=ptr->data;
            delete_val(val);
            temp->data=val;
            
          }
          else if(temp->lchild || temp->rchild)///one child
          { struct node *child= (temp->lchild)?temp->lchild:temp->rchild;
            if(parent==temp)
            {
                root=child;
            }
            else
            {  
                if(parent->data<val)
                  parent->rchild=child;
                else
                  parent->lchild=child;
             }
          }
        else//no child
          {
            if(parent==temp)//printf("*i**");
            {
              root=NULL;
            }
            else
              if(parent->data<val)
                parent->rchild=NULL;
              else
                parent->lchild=NULL;
              
          }
        }
    }
}
void delete()
{
  struct node *temp;
  int val,ch;
  printf("\n Enter choice:\n 1.one child \n2.two child\n ");
  scanf("%d",&ch);
  printf("\n Enter value to be deleted:");
  scanf("%d",&val);
  temp=search(val);
  switch(ch)
  {
    case 1:if((temp->lchild==NULL && temp->rchild) || (temp->rchild==NULL && temp->lchild))
              delete_val(val);
            else
              printf("\n The given node is not the parent of one child!!\n");
            break;
    case 2:if(temp->lchild && temp->rchild)
             delete_val(val);
            else 
              printf("\n The given node is not the parent of two child!!\n");
            break;
  }
}
void create_new_node(int val)
{
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=val;
  newNode->lchild=NULL;
  newNode->rchild=NULL;
}
void insert()
{
    struct node *temp,*parent;
    int val;
    printf("\n Enter the element:");
    scanf("%d",&val);
    create_new_node(val);
    if(root==NULL)
      root=newNode;
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(temp->data > newNode->data)
             temp=temp->lchild;
            else
             temp=temp->rchild;
        }
        if(parent->data>newNode->data)
          parent->lchild=newNode;
        else if (parent->data<newNode->data)
          parent->rchild=newNode;
        else
          printf("\n Elements should be Distinct\n");
    }
}
void inorder_traversal(struct node *nod)
{
  if(nod==NULL)
    return;
    inorder_traversal(nod->lchild);
    printf(" %d ",nod->data);
    inorder_traversal(nod->rchild);  
}
void main()
{
 int ch=0,val,l;
 while(ch!=6)
 {
   printf("\n Select an operation: \n  1.Insertion\n  2.Deletion\n  3.Inorder Traversal\n 4.Leaf count \n  5.DIsplay Right and Left children\n 6.Quit\n ");
   scanf("%d",&ch);
   switch (ch)
   {
   case 1:insert();
     break;
   case 2:
         delete();
         break;
   case 3:if(root==NULL)
           printf("\n No Elements\n");
          else
          {
              printf("\n Inorder:");inorder_traversal(root);
              break;
              }
   case 6:printf("\n Quitting...!"); 
     break;
     case 4:l=leaf_count(root);
     printf("\n no.of Leaves=%d\n",l);
            break;
     case 5:find_left_right_child();
     
            break;
   default:printf("\n Wrong Choice..!");
     break;
   }
  }
 }