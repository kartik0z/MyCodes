#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data[50];
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
} TreeNode;

TreeNode* createNode(const char* data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->data, data);
    newNode->firstChild = newNode->nextSibling = NULL;
    return newNode;
}

void addChild(TreeNode* parent, TreeNode* child) {
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        TreeNode* temp = parent->firstChild;
        while (temp->nextSibling) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void printTree(TreeNode* root, int level) {
    if (!root) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s\n", root->data);
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int main() {
    TreeNode* root = createNode("Electronics");

    TreeNode* laptop = createNode("Laptop");
    addChild(laptop, createNode("Mac"));
    addChild(laptop, createNode("Dell"));

    TreeNode* phone = createNode("Phone");
    addChild(phone, createNode("iPhone"));
    addChild(phone, createNode("Samsung"));

    TreeNode* tv = createNode("TV");
    addChild(tv, createNode("Sony"));
    addChild(tv, createNode("LG"));

    addChild(root, laptop);
    addChild(root, phone);
    addChild(root, tv);

    printf("Generic Tree:\n");
    printTree(root, 0);

    return 0;
}