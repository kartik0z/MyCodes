#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode* createNode(int key) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* root, int key) {
    if (!root) return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

int search(BSTNode* root, int key) {
    if (!root) return 0;
    if (key == root->key) return 1;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

void inorder(BSTNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

BSTNode* findMin(BSTNode* root) {
    while (root->left) root = root->left;
    return root;
}

BSTNode* deleteNode(BSTNode* root, int key) {
    if (!root) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (!root->left) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        BSTNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    BSTNode* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Delete 70\n");
    root = deleteNode(root, 70);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}