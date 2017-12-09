#include <stdio.h>
#include <stdlib.h>

void Insert();
void Delete();
void Print();

struct node
{
    int data;
    struct node *rear;
};
struct node *front=NULL;

int main()
{
    int choice;
    START:
    printf("\n1.Insert\n2.Delete\n3.Print\n4.Clear Screen\n5.Exit\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                Insert();
                break;
        case 2:
                Delete();
                break;
        case 3:
                Print();
                break;
        case 4: system("cls");
                goto START;
                break;
        case 5: printf("\nExiting");
        default: printf("Error! Wrong Choice");
        }
    }while(choice!=5);
    return 0;
}

void Insert()
{
    if(front==NULL)
    {
        struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&ptr->data);
        ptr->rear=NULL;
        front=ptr;
    }
    else
    {
        struct node *ptr,*cpt;
        ptr=front;
        while(ptr->rear!=NULL)
        {
            ptr=ptr->rear;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&cpt->data);
        cpt->rear=NULL;
        ptr->rear=cpt;
    }
}

void Delete()
{
    if(front==NULL)
    {
        printf("Underflow: Queue is Empty");
    }
    else
    {
        struct node *ptr;
        ptr=front;
        printf("Element Deleted : %d",ptr->data);
        ptr->data=(int)NULL;
        front=ptr->rear;
        ptr->rear=NULL;
    }
}
void Print()
{
    if(front==NULL)
    {
        printf("Underflow: Queue is Empty");
    }
    else
    {
        struct node *ptr;
        ptr=front;
        while(ptr!=NULL)
        {
            printf(" %d",ptr->data);
            ptr=ptr->rear;
        }
    }
}
