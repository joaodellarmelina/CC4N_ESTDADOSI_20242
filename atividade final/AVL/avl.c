#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int getHeight(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(AVLNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* createNode(int value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    return y;
}

AVLNode* insertAVLNode(AVLNode* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insertAVLNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertAVLNode(node->right, value);
    } else {
        return node;
    }
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && value < node->left->value) {
        return rotateRight(node);
    }
    if (balanceFactor < -1 && value > node->right->value) {
        return rotateLeft(node);
    }
    if (balanceFactor > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void inOrderTraversalAVL(AVLNode* root) {
    if (root != NULL) {
        inOrderTraversalAVL(root->left);
        printf("%d ", root->value);
        inOrderTraversalAVL(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    int n, i, value;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    printf("Elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertAVLNode(root, value);
    }

    printf("Ordenado pela Árvore de Pesquisa Binária: ");
    inOrderTraversalAVL(root);
    printf("\n");

    return 0;
}