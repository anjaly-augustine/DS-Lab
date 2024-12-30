#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*next;
};
struct Node*head=NULL;
struct Node*createNode(int data)
{
	struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
void insertAtFront(int data)
{
	struct Node*newNode=createNode(data);
	newNode->next=head;
	head=newNode;
}
void insertAtEnd(int data)
{
	struct Node*newNode=createNode(data);
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	struct Node*temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newNode;
}
void insertAtPosition(int data,int position)
{
	if(position<1)
	{
		printf("Position should be greater than or eqaul to 1");
		return;
	}
	if(position==1)
	{
		insertAtFront(data);
		return;
	}
	struct Node*newNode=createNode(data);
	struct Node*temp=head;
	for(int i=1;i<position-1&&temp!=NULL;i++)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Position is greater than the length of the list\n");
		free(newNode);
	}
	else
	{
		newNode->next=temp->next;
		temp->next=newNode;
	}
}
void deleteAtFront()
{
	if(head==NULL)
	{
		printf("List is empty!");
		return;
	}
	struct Node*temp=head;
	head=head->next;
	free(temp);
}
void deleteAtEnd()
{
	if(head==NULL)
	{
		printf("List is empty!");
		return;
	}
	struct Node*temp=head;
	if(temp->next==NULL)
	{
		free(temp);
		head=NULL;
		return;
	}
	struct Node*prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
}
void deleteAtPosition(int position)
{
	if(head==NULL)
	{
		printf("List is empty!");
		return;
	}
	if(position<1)
        {
                printf("Position should be greater than or equal to 1");
                return;
	}
	if(position==1)
	{
		deleteAtFront();
		return;
	}
	struct Node*temp=head;
	struct Node*prev=NULL;
	for(int i=1;i<position&&temp!=NULL;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Position is greater than length of list");
	}
	else
	{
		prev->next=temp->next;
		free(temp);
	}
}
void display()
{
	struct Node*temp=head;
	if(temp==NULL)
	{
		printf("List is empty!");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int choice,data,position;
	do
	{
		printf("\n Select operation: ");
		printf("\n1.Insert at front");
		printf("\n2.Insert at end");
		printf("\n3.Insert at position");
		printf("\n4.Delete at front");
		printf("\n5.Delete at end");
		printf("\n6.Delete position");
		printf("\n7.Display");
		printf("\n8.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				printf("Enter data to  insert at front:");
				scanf("%d",&data);
				insertAtFront(data);
				break;
			case 2:
				printf("Enter data  to insert at end:");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			case 3:
                                printf("Enter data to  insert:");
                                scanf("%d",&data);
				printf("Enter position to insert:");
				scanf("%d",&position);
                                insertAtPosition(data,position);
                                break;
                        case 4:
                                deleteAtFront();
                                break;

			case 5:
                                deleteAtEnd();
                                break;
                        case 6:
                                printf("Enter position to delete:");
                                scanf("%d",&position);
                                deleteAtPosition(position);
                                break;
			case 7:
				display();
				break;
			case 8:
				printf("Exit\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	while(choice!=8);
	return 0;
}

