#include<stdio.h>
#include<stdlib.h>
const int SIZE=10;
struct hash
{
    int val;
    int occu;
}hashtable[11];


struct ohash
{
    int val;
    struct ohash *next;
}*ohashtable[10],*newNode;


int hashfun_mod(int key)
{
    int i=key%SIZE +1;
    return i;
}
int circular_search(int i)
{
    int val=i%SIZE+1;
    while(val!=i)
    {   if(hashtable[val].occu==0)
            return val;
        val=val%SIZE+1;
    }
    return -1;
}
int search(int ele)
{
    int index,n_index;
    index=hashfun_mod(ele),n_index=index;
    do
    {
      if(hashtable[n_index].val==ele && hashtable[n_index].occu==1)
         {
             printf("\n %d is found at index %d\n",hashtable[n_index].val,n_index);
             return 1;
         }
      n_index=n_index%SIZE + 1;//n_index=3
    } while (n_index!=index);
    return 0;
}
void insert(int index,int ele)
{////printf("\n Element %d",ele);//int index=hashfun_mod(ele);
    if(search(ele)==0) //if(1)
    {
        if(hashtable[index].occu==0)
        {
            hashtable[index].val=ele;
            hashtable[index].occu=1;
            printf("\n %d is added at index %d\n",hashtable[index].val,index);  
        }
        else 
        {
            index=circular_search(index);
            if(index>0)
            insert(index,ele);
            else
            printf("\n Size full"); }     
    }
    else printf("\n Elements should be unique\n");
}
void display()
{ int i;
    for(i=1;i<=10;i++)
     if(hashtable[i].occu==1)
      printf("\n Index %d: %d",i,hashtable[i].val);
     else
      printf("\n Index %d: NO VALUE",i);//   {//      if(hashtable[i].occu==1)//         {printf("\n    %d     at index %d",hashtable[i].val,i);}//      else//         {(printf("\n NO VALUE at index %d",hashtable[i].val,i));}//  }
}
void closedhashing()
{
    int ch=0,i,ele;//struct hash ;// for(int i=1;i<=10;i++)//   printf("\n %d at index %d",hashtable[i].occu,i);initialize();
    while(ch!=4)
    {// for(int i=1;i<=10;i++)//   printf("\n %d at index %d",hashtable[i].occu,i);
        printf("\n\n Select an option:\n 1)Insertion\n 2)Search\n 3)Display\n 4)Quit\n\n ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter Element:");
            scanf("%d",&ele);
            int index=hashfun_mod(ele);
            insert(index,ele);
            break;
        case 2:
            printf("\n Enter Element to be searched:");
            scanf("%d",&ele);
            i=search(ele);
            if(i==0)
             printf("\n %d is not found!!\n",ele);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n Quitting...");
            break;
        default:
            printf("\n Wrong Choice!!");
            break;
        }
    }
}

//open hashing
int hashfun_rem(int key)
{
    return key%10;
}
void create_new_node(int ele)
{
    newNode=(struct ohash*)malloc(sizeof(struct ohash));
    newNode->val=ele;
    newNode->next=NULL;
}
int osearch(int ele)
{
    int i=hashfun_rem(ele),n=1;
    struct ohash *temp=ohashtable[i];
    while(temp!=NULL && temp->val!=ele)
    {   temp=temp->next;
        n++;   }
    if(temp==NULL)
      return 0;
    else
      {printf("\n %d is found at index %d (%dth node) \n ",ele,i,n);
       return 1;}
}
void oinsert(int ele)
{
    if(osearch(ele)==0)
    {
        struct ohash *temp;
        int index=hashfun_rem(ele);
        create_new_node(ele);
        if(ohashtable[index]==NULL)
        ohashtable[index]=newNode;
        else
        {   temp=ohashtable[index];
            while (temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;   
        }  
        printf("\n %d is added at index %d\n",ele,index);  
    }
    else printf("\n Elements should be unique\n");
}
void odisplay()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("\n Index %d: ",i);
        if(ohashtable[i]==NULL)
            printf("NO VALUE");
        else
        {
            struct ohash *temp=ohashtable[i];
            while(temp!=NULL)
            {   printf("%d ",temp->val);
                temp=temp->next;    }
        }
    }
}
void openhashing()
{
    int ch=0,i,ele;//initialize();// void initialize()// {//     for(int i=1;i<=0;i++)//       hashtable[i].occu=10;// }
    while(ch!=4)
    {
        printf("\n\n Select an option:\n 1)Insertion\n 2)Search\n 3)Display\n 4)Quit\n\n ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter Element:");
            scanf("%d",&ele);
            oinsert(ele);
            break;
        case 2:
            printf("\n Enter Element to be searched:");
            scanf("%d",&ele);
            i=osearch(ele);
            if(i==0)
             printf("\n %d is not found!!\n",ele);
            break;
        case 3:
            odisplay();
            break;
        case 4:
            printf("\n Quitting...");
            break;
        default:
            printf("\n Wrong Choice!!");
            break;
        }
    }
}
void main()
{
    int ch;
    printf("\n\n Select an option:\n 1)Open Hashing\n 2)Closed Hashing\n\n ");
    scanf("%d",&ch);
    switch (ch)
    {case 1:
        openhashing();
        break;
    case 2:
        closedhashing();
        break;          }
}
