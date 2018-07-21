#include<stdio.h>
#include<malloc.h>

typedef struct Node
	{
		int i;
		struct Node *next;
	}node;

node * insert(int key, node *head);
int removee(int key, node *head);
void search(int key, node *head);
node * append(int key, node*head);
void print(node *head);
void print_reverse(node *head);
void clear(node * head);

void menu( )
{
	printf("\n1. To Insert a Node");
	printf("\t2. To Remove a Node");
	printf("\t3. To Search a Node");
	printf("\t4. To Append a Node");
	printf("\n5. To Print a List");
	printf("\t6. To Print a list in Reverse order");
	printf("\t\t7. To Clear a List");
	printf("\n-1. To Exit");
}




int main()
{
	
	int value, key;
	node *head=NULL;
	
	menu();
	while(1)
	{
		printf("\n\nEnter an Operation Value:");
		scanf("%d",&value);
		
		if(value==-1)
			break;
			
		switch(value)
		{
			
			case 0:
			printf("Error");
			break;
			
			case 1:
			printf("\tEnter a Node value to insert: ");
			scanf("%d",&key);
			head=insert(key,head);
			break;
			
			case 2:
			printf("\tEnter a Node value to remove: ");
			scanf("%d",&key);
			removee(key,head);
			break;
			
			case 3:
			printf("\tEnter a Node value to search: ");
			scanf("%d",&key);
			search(key,head);
			break;
			
			case 4:
			printf("\tEnter a Node value to be appended: ");
			scanf("%d",&key);
			head=append(key,head);	
			break;
			
			case 5:
			printf("\t Displaying Elements in the List: ");
			print(head);
			break;
			
			case 6:
			printf("\t Displaying Elements in Reverse Order: ");
			print_reverse(head);
			if(!head)
				printf("List is Empty");
			break;
			
			case 7:
			printf("\t Performing Clear operation on the List: ");
			clear(head);
			break;
			
		}
			
	}
}

node * insert(int key, node *head)
{
	
	node *a = (node *)malloc(sizeof(node));
	a->i=key;
	a->next=NULL;
	
	if(!head)
	{
		head=a;
		return head;
	}	
	
	else
	{
		node *p=head;
		node *q=NULL;
		
		while(p!=NULL&&key>p->i)
		{
			q=p;
			p=p->next;
		}
		
		if(q==NULL)
		{
			a->next=head;
			head=a;
		}
		
		else
		{
			a->next=p;
			q->next=a;	
		}

	return head;
	}
}


int removee(int key, node *head)
{
	int result=-1;
	if(!head)
		printf("No Nodes in the list");
		
		
	node *p=head;
	node *q=NULL;
	
	while(p&&key!=p->i)
	{
		q=p;
		p=p->next;
	}
	
	if(p)
	{
		
		if(!q)
			head=head->next;
		
		else
			q->next=p->next;
			
		free (p);
		result=0;
	}
	return result;	
}
	
void search(int key, node *head)
{
		
	if(head)
	{
	node *a=head;
	while(a)
	{
		if(a->i==key)
		{
			printf("\tKey  is Found in the List");
		}
	a=a->next;
	}
	}
	
	else
		printf("\nList is Empty");
	return;
	
		
	
}

node * append(int key, node*head)
{
	node *a = (node *)malloc(sizeof(node));
	a->i=key;
	a->next=NULL;
	
	if(!head)
	{
		head=a;
		return head;
	}
	node *p = head;
	
	while(p->next)
		p=p->next;
	
	p->next = a;
	return head;
}

void print(node *head)
{
	if(!head)
		printf("List is empty");
	
	else
	{
		node *a=head;
		while(a)
		{
			printf("%d==>",a->i);
			a=a->next;
		}	
		printf("NULL");
	}
}

void print_reverse(node *head)
{
	if(head){
		print_reverse(head->next);
		printf("%d==>",head->i);
	}
}

void clear(node * head)
{
	if(!head)
	{
		printf("\nNo list is present to clear");
		return;
	}
	
	else
	{
		node * a =head;
		
		while(head)
		{
			head=head->next;
			free (a);
		}

		printf("\nList is Cleared");
	}
}
