#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*next;
};
void main()
{
   struct node *head,*p,*y;
   int i,a;
   p=(struct node*)malloc(sizeof(struct node));
   printf("enter the data\n");
   scanf("%d",&(p->info));
   p->next=NULL;
   head=p;
   printf("\ndo you wish to continue");
   scanf("%d",&i);
   while(i)
   {
   	y=(struct node*)malloc(sizeof(struct node));
   printf("enter the data\n");
   scanf("%d",&(y->info));
   p->next=y;
   y->next=NULL;
   p=y;
   printf("\ndo you wish to continue");
   scanf("%d",&i);
   }
   printf("\nthe data is \n");
   p=head;
   while(p!=NULL)
   {
   	printf("%d",p->info);
   	p=p->next;
   }
   	
}
