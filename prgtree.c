
#include<stdio.h>
int front=-1,rear=-1,queue[20],stack[20],top=-1,visited[20];
void enqueue(int val,int i)
{
    //if(visited[i]==0)
    {if(front==-1)
      rear=front=0;
    else
      rear++;
    queue[rear]=val;
    visited[i]=1;}
}
void dequeue()
{
    printf(" %d",queue[front]);
    if(front==rear)
      front=rear=-1;
    else
     front++;
}
void push(int val,int i)
{
  top++;
  stack[top]=val;
  printf(" %d",val);
  visited[i]=1;
}
void pop()
{
  top--;
}

int find_index(int val,int *ver,int n)
{//0 0 1 0 0 0 1 0 0 0
  int i;
    for(i=0;i<n;i++)
     if(val==*(ver+i))
       {break;}
    return i;
}

void bfs(int adj[20][20],int n,int *ver)
{
    int i,j,temp,src;// for(i=0;i<n;i++)//  for(j=0;j<n;j++)//    printf("%d ",*(ver+i));
    printf("\n Enter Source:");
    scanf("%d",&src);
    i=find_index(src,ver,n);
    if(i<n)
    {
      enqueue(*(ver+i),i);
      for(j=0;j<n;j++)
            if(adj[i][j]==1 && visited[j]==0)//if(check_val(find_index(*(ver+j),ver,n)))
                enqueue(*(ver+j),j);
      dequeue();
      while(front!=-1)
      {//temp=*(ver+i);
          i=find_index(queue[front],ver,n);
          for(j=0;j<n;j++)
            if(adj[i][j]==1 && visited[j]==0)// if(check_val(find_index(*(ver+j),ver,n)))
                enqueue(*(ver+j),j);
          
          dequeue();
      }
    }
    else
    {
      printf("Wrong source!!");
      bfs(adj,n,ver);
    }
}
//recursive
// void bfs(int adj[20][20],int n,int *ver,int src)
// {
//     int i,j;// for(i=0;i<n;i++)//  for(j=0;j<n;j++)//    printf("%d ",*(ver+i)); 
//     i=find_index(src,ver,n);
//     if(i<n)
//     {
//         enqueue(*(ver+i),i);
//         for(j=0;j<n;j++)
//             if(adj[i][j]==1 )//if(check_val(find_index(*(ver+j),ver,n)))
//                 enqueue(*(ver+j),j);
//         dequeue();//dfs(adj,n,ver,stack[top]);
//         if(front>-1)
//           bfs(adj,n,ver,queue[front]);
//     }
//     else
//     {
//       printf("Wrong source!!");
//       printf("\n Enter Source:");
//       scanf("%d",&src);
//       bfs(adj,n,ver,src);
//     }
// }

void dfs(int adj[20][20],int n,int *ver,int src)
{
  int i,j;// for(i=0;i<n;i++)//  for(j=0;j<n;j++)//    printf("%d ",adj[i][j]);// printf("\n Enter Source:");// scanf("%d",&src);
    i=find_index(src,ver,n);
    if(i<n)

    {
        push(src,i);
        visited[i]=1;
        for(j=0;j<n;j++)
            if(adj[i][j]==1 && visited[j]==0)//if(check_val(find_index(*(ver+j),ver,n)))
                dfs(adj,n,ver,*(ver+j));
        pop();
    }
    else
      printf("Wrong source!!");
    
}
//non-recursive
// void dfs(int adj[20][20],int n,int *ver,int src)
// {
//   int i,j;// for(i=0;i<n;i++)//  for(j=0;j<n;j++)//    printf("%d ",adj[i][j]);// printf("\n Enter Source:");// scanf("%d",&src);
//     i=find_index(src,ver,n);
//     if(i<n)
//     {
//         push(src,i);
//         while(top>-1)
//         {
//           i=find_index(stack[top],ver,n);
//           for(j=0;j<n;j++)
//             if(adj[i][j]==1 && visited[j]==0)
//               { push(*(ver+j),j);
//                 break;
//               }
//           if(j==n)
//            pop();          
//         }
//     }
//     else
//       printf("Wrong source!!");  
// }

void main()
{
    int v,i,j,adj_m[20][20],nodes[20],src;
    printf("\n Enter the number of vertices:");
    scanf("%d",&v);
    printf("\n Enter value of all nodes:");
    for(i=0;i<v;i++)
      {scanf("%d",&nodes[i]);
      visited[i]=0;}
    printf("\n Enter the Adjecency Matrix:"
    );
    for(i=0;i<v;i++)
     for(j=0;j<v;j++)
      scanf("%d",&adj_m[i][j]);// for(i=0;i<v;i++)//  for(j=0;j<v;j++)//    printf("%d ",adj_m[i][j]);
    printf("\n Breadth First Search:");
    bfs(adj_m,v,nodes);
    for(i=0;i<v;i++)
       visited[i]=0;
    printf("\n Depth First Search:");
    printf("\n Enter Source:");
    scanf("%d",&src);
    dfs(adj_m,v,nodes,src);
}
