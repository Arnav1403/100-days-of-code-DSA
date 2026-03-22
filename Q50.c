#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
int main() {
    int n, x;
    scanf("%d", &n);
    int values[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);
    scanf("%d", &x);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    if (search(root, x))
        printf("Found\n");
    else
        printf("Not Found\n");
    return 0;
}
