#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(Node* node) {
    queue[rear++] = node;
}

Node* dequeue() {
    return queue[front++];
}

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int search(Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    return search(root->left, key) || search(root->right, key);
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void bfs(Node* root) {
    if (root == NULL) return;

    front = rear = 0;
    enqueue(root);

    while (front < rear) {
        Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left != NULL)
            enqueue(curr->left);
        if (curr->right != NULL)
            enqueue(curr->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nBFS: ");
    bfs(root);

    printf("\nSearch 7: %s", search(root, 7) ? "Found" : "Not Found");
    printf("\nNode count: %d", countNodes(root));
    printf("\nHeight: %d\n", height(root));

    return 0;
}
