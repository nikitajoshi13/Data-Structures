#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*next;
	
};

struct node *head;
void create();
void traverse();
void insert_beg();
void insert_end();
void insert_any();
void delete_beg();
void delete_end();
void delete_any();
void search();
void count();
   void main()
   {
   	 int option;
   	 
     do
     {
     	printf("\n*****************MAIN MENU****************");
		printf("\n 1. Create a list");
		printf("\n 2. Traverse the  list");
		printf("\n 3. Add a node at the beginning");
		printf("\n 4. Add a node at the end");
		printf("\n 5. Add a node at any other position");
		printf("\n 6. Delete a node from the beginning");
		printf("\n 7. Delete a node from the end");
		printf("\n 8. Delete a given node");
		printf("\n 9. Search a node in the list");
		printf("\n 10. Count the number of nodes in the list");
		printf("\n 11. EXIT");
		 printf("\n Enter your option");
     	scanf("%d",&option);
     	switch(option)
     	{
     		case 1:
     			create();
     			break;
     		case 2:
     			traverse();
     			break;
     		case 3:
     			insert_beg();
     			break;
     		case 4:
     			insert_end();
     			break;
     		case 5:
     		    insert_any();
     		    break;
     		case 6:
     			delete_beg();
     			break;
     		case 7:
     			delete_end();
     			break;
     		case 8:
     			delete_any();
     			break;
     		case 9:
			    search();
				break;
			case 10:
			    count();
				break;
			default:
			printf("wrong input\n");
			exit(0);	
				 	
       }
  }while(option!=11);
}

void create()
{
	int i,n;
struct node *p,*x,*y;
p=(struct node*)malloc(sizeof(struct node));
printf("\nenter info for first node\n ");
scanf("%d",&p->info);
head=p;
p->next=p;
printf("\ndo you wish to continue\n");
printf("\npress 1 for yes and 0 for no\n");
scanf("%d",&i);
while(i)
{
	x=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the info for the node\n ");
    scanf("%d",&x->info);
    p->next=x;
    x->next=head;
	p=x;
	printf("\ndo you wish to continue\n");
    printf("\npress 1 for yes and 0 for no\n");
    scanf("%d",&i);
}
     			
}
void traverse()
{
	struct node *p;
	p=head;
	printf("\nthe linked list is\n");
	do
	{
		printf("%d",p->info);
		p=p->next;
	}while(p!=head);
}
void insert_beg()
{
	struct node *p,*x;
	p=(struct node*)malloc(sizeof(struct node));
printf("\nenter info for the node\n ");
scanf("%d",&p->info);
    x=head;
    while(x->next!=head)
    {
    	x=x->next;
	}
	x->next=p;
	p->next=head;
	head=p;
}
void insert_end()
{
	struct node *p,*x;
	x=(struct node*)malloc(sizeof(struct node));
printf("\nenter info for the node\n ");
scanf("%d",&x->info);
	p=head;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=x;
	x->next=head;
}
void insert_any()
{
	struct node *p,*x;
	int j,k,m=1;
	p=(struct node*)malloc(sizeof(struct node));
    printf("\nenter info for the node\n ");
    scanf("%d",&p->info);
	printf("enter the position after which you need to insert the new node\n");
	scanf("%d",&k);
	x=head;
	while(m<k)
	{
		x=x->next;
		m++;
	}
	p->next=x->next;
	x->next=p;
}
void delete_beg()
{
	struct node *p,*temp;
	p=head;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=head->next;
	temp=head;
	head=head->next;
	free(temp);
}
void delete_end()
{
   struct node *p,*temp;
   p=head;
   while(p->next->next!=head)
   {
     p=p->next;
   }
   temp=p->next;
   p->next=head;
   free(temp);
}
void delete_any()
{
  struct node *p,*temp;
  int n,m=1;
  printf("enter the value you want to delete");
  scanf("%d",&n);
  p=head;
  while(p->next->info!=n)
  {
   p=p->next;
  }
   /*or this can also be done when node number is given
   printf("enter the node number you want to delete");
  scanf("%d",&n);
  p=head;
  while(m<n-1)
  {
    p=p->next;
    m++;
  }*/
  printf("%d",p->info);
    temp=p->next;
  p->next=temp->next;
  free(temp);
}
void search()
{
  struct node *p;
  int n,flag=0;
  printf("enter the item you want to search");
  scanf("%d",&n);
  p=head;
  do
  {
  	if(p->info==n)
  	{
  		flag=1;
  		break;
	  }
	else
	p=p->next;
  }while(p!=head);
  
   if(flag==1)
{
 printf("search successful");
}
else
printf("search unsucessful");
}
void count()
{
struct node *p;
int i=0;
p=head;
do
	{
		p=p->next;
		i++;
	}while(p!=head);
printf("number of nodes are %d",i);
}
  
