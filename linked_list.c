/*Program of single linked list
By Tathagata Mandal (BCA)*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item );
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start=NULL;	
	int choice,data,item,pos;
		
	while(1)
	{
		printf("\n\n------- MAIN MENU -------\n\n");
		printf("1.  CREAT LINKED LIST\n");
		printf("2.  DISPLAY\n");
		printf("3.  COUNT\n");
		printf("4.  SEARCH\n");
		printf("5.  ADD AT BEGINNING\n");
		printf("6.  ADD AT END\n");
		printf("7.  ADD AFTER NODE\n");
		printf("8.  ADD BEFORE NODE\n");
		printf("9.  Add AT POSSITION\n");
		printf("10. DELETE\n");
		printf("11. REVERSE\n");
		printf("12. EXIT\n\n");
		
		printf("\nENTER YOUR CHOICE : \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		 case 1:
			start=create_list(start);
			break;
		 case 2:
			display(start);
			break;
		 case 3:
			count(start);
			break;
		 case 4:
			printf("\nENTER THE SEARCH ELEMENT : \n");
			scanf("%d",&data);
			search(start,data);
			break;
		 case 5:
			printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		 case 6:
			printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
			scanf("%d",&data);
			start=addatend(start,data);
			break;
		 case 7:
			printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
			scanf("%d",&data);
			printf("\nENTER THE ELEMENT AFTER WHICH TO INSERT : \n");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;
		 case 8:
			printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
			scanf("%d",&data);
			printf("\nENTER THE ELEMENT BEFORE WHICH TO INSERT : \n");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		 case 9:
			printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
			scanf("%d",&data);
			printf("\nENTER THE POSITION AT WHICH TO INSERT : \n");
			scanf("%d",&pos);
			start=addatpos(start,data,pos);
			break;
		 case 10:
			printf("\nENTER THE ELEMENT TO BE DELETED : \n");
			scanf("%d",&data);
			start=del(start, data);	
			break;
		 case 11:
			start=reverse(start);
			break;
		 case 12:
			 exit(1);
		 default:
			 printf("\nINVALID CHOICE\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("\nENTER THE NUMBER OF NODES : \n");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
	scanf("%d",&data);
	start=addatbeg(start,data);

	for(i=2;i<=n;i++)
	{
		printf("\nENTER THE ELEMENT TO BE INSERTED : \n");
		scanf("%d",&data);
		start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nLIST EMPTY\n");
		return;
	}
	p=start;
	printf("\nTHE LIST IS : ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of display() */

void count(struct node *start)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	printf("\nTHE NUMBER OF ELEMENT ARE : %d\n",cnt);
}/*End of count() */

void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("\nITEM %d FOUND AT POSITION %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("\nITEM %d NOT FOUND\n",item);
}/*End of search()*/

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of addatbeg()*/

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of addatend()*/

struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("\n%d NOT PRESENT IN LIST\n",item);
	return start;
}/*End of addafter()*/

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	if(start==NULL )
	{
		printf("\nLIST EMPTY\n");
		return start;
	}	
	/*If data to be inserted before first node*/
	if(item==start->info)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}	
	p=start;
	while(p->link!=NULL) 
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("\n%d NOT PRESENT IN LIST\n",item);
	return start;
}/*End of addbefore()*/	

struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start; 
		start=tmp;
		return start;
	}
	p=start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		printf("There are less than %d elements\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}	
	return start;
}/*End of addatpos()*/

struct node *del(struct node *start,int data)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		printf("\nLIST IS EMPTY\n");
		return start;
	}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->link;  
		free(tmp);
		return start;
	}
	/*Deletion in between or at the end*/
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("\nELEMENT %d NOT FOUND\n",data);
	return start;
}/*End of del()*/

struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}/*End of reverse()*/