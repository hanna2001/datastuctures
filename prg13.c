#include <stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *lchild;
    struct node *rchild;
    
}*Stack[10];
int top=-1;
struct node* createNewNode(int key)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->val=key;
    newNode->rchild=NULL;
    newNode->lchild=NULL;    
    return newNode;}
    
struct node* search(struct node *node,int key)
{
    if(node==NULL || node->val==key)
     return node;
    if(key<node->val)
     return search(node->lchild,key);
    else
     return search(node->rchild,key);
    
}
    
struct node* insert(struct node *node,int key)
{
    if(node==NULL)
        return createNewNode(key); 
    if(node->val==key)
        printf("\n Elements should be unique");
    else if(key>node->val)                   
            node->rchild=insert(node->rchild,key);               
         else                   
            node->lchild=insert(node->lchild,key);
    return node;
    
}

struct node* findMin(struct node *temp)
{
    while(temp->lchild!=NULL)
     temp=temp->lchild;
    return temp;
}

struct node* delete(struct node *node,int key)
{
    if(node==NULL)
        printf("\n No such Element");
    else{
            if(key<node->val)
            node->lchild=delete(node->lchild,key);
            else if(key>node->val)
            node->rchild=delete(node->rchild,key);
            else
            {
                if(node->lchild==NULL)
                {
                    node=node->rchild;
                    return node;
                }
                if(node->rchild==NULL)
                {
                    node=node->lchild;
                    return node;
                }
                struct node *temp=findMin(node->rchild);
                node->val=temp->val;
                node->rchild=delete(node->rchild,temp->val);
                return node;
                
            }
              
        }
     
    return node;
}




int leaf_count(struct node *node)
{
    if(node==NULL)
      return 0;
    if(node->lchild==NULL && node->rchild==NULL)
      return 1;
    return leaf_count(node->lchild)+leaf_count(node->rchild);
}

void inorder(struct node *node)
{  
    if(node!=NULL)
    {
        inorder(node->lchild);
        printf(" %d ",node->val);
        inorder(node->rchild);  
        
    }
    
}

int parent(struct node *node,int par_val,int child_val)
{
    if(node==NULL)
      return -1;
    if(node->val==child_val)
      return par_val;
    if(child_val>node->val)
      parent(node->rchild,node->val,child_val);
    else if(child_val<node->val)
      parent(node->lchild,node->val,child_val);
     
}

void preorder_traversal(struct node *node)
{
  if(node!=NULL)
    {printf(" %d ",node->val);
    preorder_traversal(node->lchild);
    preorder_traversal(node->rchild);  }
}

void push(struct node *item)
{
    top++;
    Stack[top]=item;
}

struct node* pop()
{
    printf("%d ",Stack[top]->val);
    return Stack[top--];
}

void preorder_stack(struct node *root)
{
    push(root);
    while(top!=-1)
    {
    struct node *ptr=pop();
    if(ptr->rchild)
        push(ptr->rchild);
    if(ptr->lchild)
        push(ptr->lchild);
    }
}
void postorder_traversal(struct node *node)
{
  if(node==NULL)
    return;
    postorder_traversal(node->lchild);
    postorder_traversal(node->rchild);
    printf(" %d ",node->val);  
}

void main(){
    struct node *temp,*root=NULL;
    int ch=0,ele;
    while(ch!=5)
    {
        printf("Choose: 1.Insert 2.Delete 3.Search 4.Display 6.No. of leaf nodes 7.parents");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element:");
            scanf("%d",&ele);
            root=insert(root,ele);
            break; 
            
            case 2:printf("Enter the element:");
            scanf("%d",&ele);
            root=delete(root,ele);
            break; 
            
            case 3:printf("Enter the element to be searched:");
            scanf("%d",&ele);
            temp=search(root,ele);
            if(temp->val!=ele)
             printf("\n Element not found");
            else
             printf("\n Found %d %d",ele,temp->val);
            break; 
            
            case 4:
                if(root==NULL)
                printf("\nEmpty");
                else
                  printf("\n rec ");
                  preorder_traversal(root);
                  printf("\n non rec");
                  preorder_stack(root);
                  break;
            case 6:
                printf("\n no of leaves :%d",leaf_count(root));
                break;
                
            case 7:printf("Enter the element:");
            scanf("%d",&ele);
            ele=parent(root,-1,ele);
           if(ele>=0)
             printf("\n parent:%d",ele);
            else
              printf("\n no parent");
                  }   
                  //min-max(leftmost and rightmostchild) sibling(parent,search,node->val!=key)
        
    }
    
}



// #include<stdio.h>
// #include<stdlib.h>
// struct node
// {
//     int data;
//     struct node *lchild;
//     struct node *rchild;
// }*root,*newNode;
// void create_new_node(int val)
// {
//   newNode=(struct node*)malloc(sizeof(struct node));
//   newNode->data=val;
//   newNode->lchild=NULL;
//   newNode->rchild=NULL;
// }
// void insert()
// {
//     struct node *temp,*parent;
//     int val;
//     printf("\n Enter the element:");
//     scanf("%d",&val);
//     create_new_node(val);
//     if(root==NULL)
//       root=newNode;
//     else
//     {
//         temp=root;
//         while(temp!=NULL)
//         {
//             parent=temp;
//             if(temp->data > newNode->data)
//              temp=temp->lchild;
//             else
//              temp=temp->rchild;
//         }
//         if(parent->data>newNode->data)
//           parent->lchild=newNode;
//         else if (parent->data<newNode->data)
//           parent->rchild=newNode;
//         else
//           printf("\n Elements should be Distinct\n");
//     }
// }
// struct node* findMinimum(struct node *cur)  
// {  
//     while(cur->lchild != NULL) {  
//         cur = cur->lchild;  
//     }  
//     return cur;  
// }  
// void delete(int val)
// {
//     struct node *temp,*parent,*ptr;
//     int flag=0,a;
//     {
//         temp=root;
//         parent=root;
//         while(temp!=NULL && flag!=1)
//         {
//           if(val>temp->data)//printf("***");
//             {parent=temp;
//              temp=temp->rchild;}
//             else if(val<temp->data)
//             {parent=temp;
//              temp=temp->lchild;}
//             else flag=1;
//         }
//         if(flag==1)
//         { 
//           if(temp->lchild && temp->rchild)///two child
//           { 
//             ptr=findMinimum(temp->rchild);//printf("Parent %d child %d",a);
//             val=ptr->data;
//             delete(val);
//             temp->data=val;
//             //free(ptr);
            
//           }
//           else if(temp->lchild || temp->rchild)///one child
//           { struct node *child= (temp->lchild)?temp->lchild:temp->rchild;
//             if(parent==temp)
//             {//  if(temp->lchild)//printf("***");//printf("parent %d temp%d",parent->data,parent->child->data);//    root=parent->lchild;//  else //    root=parent->rchild;//printf("parent %d root%d",parent->data,root->data);
//               root=child;
//             }
//             else
//             {  
//                 if(parent->data<val)
//                   parent->rchild=child;
//                 else
//                   parent->lchild=child;
//              }
//              free(temp);
//           }
//         else//no child
//           {
//             if(parent==temp)//printf("*i**");
//             {
//               root=NULL;
//             }
//             else
//               if(parent->data<val)
//                 parent->rchild=NULL;
//               else
//                 parent->lchild=NULL;
//               free(temp);
//           }
//         }
//     }
// }
// void inorder_traversal(struct node *node)
// {
//   if(node!=NULL)
//     {inorder_traversal(node->lchild);
//     printf(" %d ",node->data);
//     inorder_traversal(node->rchild);  }
// }
// void preorder_traversal(struct node *node)
// {
//   if(node!=NULL)
//     {printf(" %d ",node->data);
//     preorder_traversal(node->lchild);
//     preorder_traversal(node->rchild);  }
// }
// void postorder_traversal(struct node *node)
// {
//   if(node==NULL)
//     return;
//     postorder_traversal(node->lchild);
//     postorder_traversal(node->rchild);
//     printf(" %d ",node->data);  
// }

// int search(int val)
// {
//   struct node *temp;
//   int flag=0;
//   if(root==NULL)
//       flag=0;
//     else
//     {
//         temp=root;
//         //parent=root;
//         while(temp!=NULL && flag!=1)
//         {
//           if(val>temp->data)//printf("***");
//             {//parent=temp;
//              temp=temp->rchild;}
//             else if(val<temp->data)
//             {//parent=temp;
//              temp=temp->lchild;}
//             else flag=1;
//         }
        
//     }
//     return flag;

// }
// void main()
// {
//  int ch=0,val;
//  while(ch!=5)
//  {
//    printf("\n Select an operation: \n  1.Insertion\n  2.Deletion\n  3.Traversal\n  4.Searching \n  5.Quit\n ");
//    scanf("%d",&ch);
//    switch (ch)
//    {
//    case 1:insert();
//      break;
//    case 2:if(root==NULL)
//             printf("\n Underflow \n");
//         else{printf("\n Enter the element:");
//         scanf("%d",&val);
//         delete(val);}
//      break;
//    case 3:if(root==NULL)
//            printf("\n No Elements\n");
//           else
//           {printf("\n Inorder:");inorder_traversal(root);
//           printf("\n Preorder:");preorder_traversal(root);
//           printf("\n Postorder:");postorder_traversal(root);}
//           break;
//    case 5:printf("\n Quitting...!"); 
//      break;
//      case 4:printf("\n Enter the element to be Searched:");
//             scanf("%d",&val);
//             int i=search(val);
//             if(i==1)
//               printf("\n Element found!!");
//             else
//               printf("\n Element not found!!");
//             break;
//    default:printf("\n Wrong Choice..!");
//      break;
//    }
//   }
//  }

