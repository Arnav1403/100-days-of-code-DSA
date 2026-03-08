#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue() {
    if(front == NULL) {
        return;
    }

    if(front == rear) {
        free(front);
        front = rear = NULL;
    }
    else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if(front == NULL) {
        return;
    }

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
