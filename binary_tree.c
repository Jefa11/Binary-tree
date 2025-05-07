#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C) {
    int countA = countNodes(A);
    int countB = countNodes(B);
    int countC = countNodes(C);
    
    printf("\nComparison Results:\n");
    printf("Tree A has %d nodes\n", countA);
    printf("Tree B has %d nodes\n", countB);
    printf("Tree C has %d nodes\n", countC);
    
    if (countA >= countB && countA >= countC) {
        printf("Tree A has the highest number of nodes (%d)\n", countA);
    } else if (countB >= countA && countB >= countC) {
        printf("Tree B has the highest number of nodes (%d)\n", countB);
    } else {
        printf("Tree C has the highest number of nodes (%d)\n", countC);
    }
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

struct Node* buildTree() {
    int data;
    char choice;
    
    printf("Enter data for node (or -1 for NULL): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    
    struct Node* root = newNode(data);
    
    printf("Does node %d have a left child? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        root->left = buildTree();
    }
    
    printf("Does node %d have a right child? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        root->right = buildTree();
    }
    
    return root;
}

int main() {
    printf("Binary Tree Comparison Program\n");
    printf("=============================\n\n");
    
    printf("Building Tree A:\n");
    struct Node* A = buildTree();
    
    printf("\nBuilding Tree B:\n");
    struct Node* B = buildTree();
    
    printf("\nBuilding Tree C:\n");
    struct Node* C = buildTree();
    
    compareBinaryTree(A, B, C);
    
    freeTree(A);
    freeTree(B);
    freeTree(C);
    
    return 0;
}
