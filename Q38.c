#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void push_front(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if(front == NULL)
        rear = temp;
    else
        front->prev = temp;

    front = temp;
}


void push_back(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if(rear == NULL)
        front = temp;
    else
        rear->next = temp;

    rear = temp;
}


void pop_front()
{
    if(front == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted: %d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}


void pop_back()
{
    if(rear == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    struct node *temp = rear;
    printf("Deleted: %d\n", temp->data);

    rear = rear->prev;

    if(rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}


void get_front()
{
    if(front == NULL)
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", front->data);
}


void get_back()
{
    if(rear == NULL)
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", rear->data);
}


int size()
{
    int count = 0;
    struct node *temp = front;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void display()
{
    struct node *temp = front;

    if(temp == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Front Element\n");
        printf("6. Rear Element\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
