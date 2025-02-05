#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node * prev;
        int data;
        struct node * next;
};

struct node * head=NULL;

struct node * createnode(int item)
{
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->data = item;
        newnode->next = NULL;
        return newnode;
}

void insertAtFront(int item)
{
        struct node * newnode = createnode(item);
        newnode->next = head;
        head = newnode;
        printf("Item Inserted!\n");
}

void insertAtPosition(int item,int position)
{
        if(position<1)
        {
                printf("Position should be greater than or equal to 1.\n");
                return;
        }
        if(position == 1)
        {
                insertAtFront(item);
                return;
        }

        struct node * newnode = createnode(item);
        struct node * temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
                temp = temp->next;
        }
        if (temp == NULL)
        {
                printf("Invalid position!\n");
                free(newnode);
        }
        else
        {
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next = newnode;
                temp->next->prev = newnode;
                printf("Item Inserted at %d position!\n",position);
        }
}



void insertAtEnd(int item)
{
        struct node * newnode = createnode(item);
        if(head == NULL)
        {
                head = newnode;
        }
        struct node* temp = head;
        while(temp->next != NULL)
                temp = temp->next;
                temp->next = newnode;
                newnode->prev = temp;
		newnode->next=NULL;
                printf("Item Inserted!\n");
}

void deleteFromFront()
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;
    head = temp->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
    printf("Item Deleted!\n");
}


void deleteFromPosition(int position)
{
        if (head == NULL)
        {
                printf("List is empty.\n");
                return;
        }
        if (position < 1)
        {
                printf("Position should be greater than or equal to 1.\n");
                return;
        }
        if (position == 1)
        {
                deleteFromFront();
                return;
        }

        struct node* temp = head;
        struct node* loc = NULL;

        for (int i = 1; i < position && temp != NULL; i++)
        {
                loc = temp;
                temp = temp->next;
        }
        if (temp == NULL)
        {
                printf("Invalid position!\n");
        }
        else
        {
                loc->next = temp->next;
                free(temp);
                printf("Item Deleted!\n");
        }
}


void deleteFromEnd()
{
        if(head == NULL)
        {
                printf("List is empty.\n");
                return;
        }

        struct node* temp = head;
        struct node* loc = NULL;

        if(temp->next == NULL)
        {
                free(temp);
                head = NULL;
                return;
        }

        while(temp->next != NULL)
        {
                loc=temp;
                temp = temp->next;
        }
        loc->next = NULL;
        free(temp);
        printf("Item Deleted!\n");
}


void display()
{
        struct node* temp = head;
        if(temp == NULL)
        {
                printf("List is empty.\n");
                return;
        }
        while(temp != NULL)
        {
                printf("%d -> ", temp->data);
                temp = temp->next;
        }
        printf("NULL\n");
}

int main()
{
        int choice,item,position;
        do{
                printf("1.Insert at front\n2.Insert at position\n3.Insert at end\n4.Delete at front\n5.Delete at position\n");
                printf("6.Delete at end\n7.Display\n8.Exit\nEnter your choice :");
                scanf("%d",&choice);
                switch(choice)
                {
                        case(1):
                                printf("Enter item to insert at front :");
                                scanf("%d",&item);
                                insertAtFront(item);
                                break;
                        case(2):
                                printf("Enter item to be inserted :");
                                scanf("%d",&item);
                                printf("Enter the position :");
                                scanf("%d",&position);
                                insertAtPosition(item,position);
                                break;
                        case(3):
                                printf("Enter item to insert at end :");
                                scanf("%d",&item);
                                insertAtEnd(item);
                                break;
                        case(4):
                                deleteFromFront();
                                break;
                        case(5):
                                printf("Enter the position :");
                                scanf("%d",&position);
                                deleteFromPosition(position);
                                break;
                        case(6):
                                deleteFromEnd();
                                break;
                        case(7):
                                display();
                                break;
                        case(8):
                                printf("Exit\n");
                                break;
                        default:
                                printf("Invalid choice!\n");
                                break;
                }
        } while(choice!=8);

        return 0;
}


































