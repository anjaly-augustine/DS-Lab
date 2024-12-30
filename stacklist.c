#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node* top=NULL;
void push()
{
	struct node* newnode;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item:");
	scanf("%d",&item);
	newnode->data=item;
	newnode->next=top;
	top=newnode;
}
void pop()
{
	struct node* temp;
	if(top==NULL)
	{
		printf("Stack is underflow!\n");
	}
	else
	{
		printf("%d is popped out\n",top->data);
		temp=top;
		top=top->next;
		free(temp);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("Stack Underflow");
	}
	else
	{
	struct node*temp;
	printf("Stack->");
	temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	}
}
void search()
{
	struct node*temp;
	int item;
	int flag=0;
	printf("Enter the item:");
	scanf("%d",&item);
	temp=top;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			printf("Item found\n");
			flag=1;
		}
		temp=temp->next;
	}
	if(!flag)
	{
		printf("Item not found!\n");
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Search\n5.exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				search();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid choice");
			}
	}
}
