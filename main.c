#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *pNext;
};
void prtChain(Node *header)
{

	 while(header!=0)
	 {
	 	printf("%d\t",header->data);
	 	header = header ->pNext;

	 }
}
void freeChain(Node *header)
{
    Node *Tmp,*p = header->pNext;
    header->pNext = NULL;
    while(p)
    {
       Tmp=p;
       free(Tmp);
       p = p->pNext;
    }
}
void Insert(int data,Node **header)
{
    Node *p = malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Out of space!");
    }
    p->data = data;
    p->pNext = NULL;
    if(*header == 0)
    {
       *header = p;
    }
    else
    {
       if((*header)->data >= data)
       {
           p->pNext = *header;   //×¢Òâ´Ë´¦
           *header = p;
       }
       else
       {
           Node* p1 =*header,*p2 =(*header)->pNext;
           while(p2!=0&&p2->data<data)
           {
               p1=p2;
               p2=p2->pNext;
           }
           p->pNext = p2;
           p1->pNext = p;
       }
    }
}
int main()
{
   Node *header=0,*p;
   int data;
   printf("input waiting.......\n");
   while(scanf("%d",&data)!=0)
   {
       Insert(data,&header);
   }
          prtChain(header);
   return 0;
}
