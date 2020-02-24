#include <stdlib.h>
#include <stdio.h>

typedef struct BinarySearchTree {
    struct TreeNode *root;
} BinarySearchTree;

typedef struct TreeNode {
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode;

static int _insertValue(TreeNode *node, int value) {    // note: functions starting with '_' are not conforming to the C standard
    if(node->value < value) {
        if(node->rightChild == NULL) {
            node->rightChild = (struct TreeNode*) malloc(sizeof(TreeNode));
            node->rightChild->value = value;
        } else {
            _insertValue(node->rightChild, value);
        }
    } else {
        if(node->leftChild == NULL) {
            node->leftChild = (struct TreeNode*) malloc(sizeof(TreeNode));
            node->leftChild->value = value;
        } else {
            _insertValue(node->leftChild, value);
        }
    }
}

int* _inOrderTraversal(TreeNode *node) {
    if(node->leftChild != NULL) _inOrderTraversal(node->leftChild);
    printf("%d ", node->value);
    if(node->rightChild != NULL) _inOrderTraversal(node->rightChild);
}

int insertValue(BinarySearchTree *tree, int value) {
    if(tree->root == NULL) {
        tree->root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        tree->root->value = value;
    } else {
        _insertValue(tree->root, value);
    }
}

int inOrderTraversal(BinarySearchTree *tree) {
    if(tree->root != NULL) {
        _inOrderTraversal(tree->root);
    }
}

int main() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    int nums[] = {8, 16, 42, 23, 4, 15};

    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        insertValue(tree, nums[i]);
    }

    inOrderTraversal(tree);
}