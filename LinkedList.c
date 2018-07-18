#include<stdio.h>
#include<malloc.h>

typedef struct Node
	{
		int i;
		struct Node *next;
	}node;


	

node * insert(int key, node *head);
int remove(int key, node *head);
void search(int key, node *head);
node * append(int key, node*head);
void print(node *head);
void print_reverse(node *head);
void clear(node * head);

void menu( )
{
	printf("\n1. To Insert a Node");
	printf("\n2. To Remove a Node");
	printf("\n3. To Search a Node");
	printf("\n4. To Append a Node");
	printf("\n5. To Print a List");
	printf("\n6. To Print a list in Reverse order");
	printf("\n7. To Clear a List");
	printf("\n-1. To Exit");
}




int main()
{
	
	int value, key;
	node *head;
	
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
			printf("\nEnter a Node value to insert: ");
			scanf("%d",&key);
			insert(key,head);
			break;
			
			case 2:
			printf("\nEnter a Node value to remove: ");
			scanf("%d",&key);
			remove(key,head);
			break;
			
			case 3:
			printf("\nEnter a Node value to search: ");
			scanf("%d",&key);
			search(key,head);
			break;
			
			case 4:
			printf("\nEnter a Node value to be appended: ");
			scanf("%d",&key);
			append(key,head);	
			break;
			
			case 5:
			printf("\n Displaying Elements in the List: ");
			print(head);
			break;
			
			case 6:
			printf("\n Displaying Elements in Reverse Order: ");
			print_reverse(head);
			break;
			
			case 7:
			printf("\n Performing Clear operation on the List: ");
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
		head=a;
	
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


int remove(int key, node *head)
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
			
		delete p;
		result=0;
	}
	return result;	
}
	
void search(int key, node *head)
{
	if(!head)
		printf("List is empty");
		
		
	node *a=head;
	while(a)
	{
		if(a->i=key)
		{
			printf("Key %d is Found in the List", &key);
			return;
		}
	a=a->next;
	}
	
	printf("Key not Found in the List");
		
	
}

node * append(int key, node*head)
{
	node *a = (node *)malloc(sizeof(node));
	a->i=key;
	a->next=NULL;
	
	if(!head)
		head=a;
		
	node *p = head;
	
	while(p->next)
		p=p->next;
	
	p->next = a;
}

void print(node *head)
{
	if(!head)
		printf("\nList is empty");
	
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
	if(!head)
		printf("\nList is empty");
	
	else
	{
		node *a = head;
		while(a)
		{
			
			a=a->next;
			print_reverse(a);
			printf("%d==>",a->i);
		}
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
			delete a;
		}

		printf("\nList is Cleared");
	}
}
