#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue elements to stack
    for(i = front; i <= rear; i++) {
        push(dequeue());
    }

    // Move stack elements back to queue
    while(top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
