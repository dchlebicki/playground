#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode;

int insertValue(TreeNode *node, int value) {
    if(node->value < value) {
        if(node->rightChild == NULL) {
            node->rightChild = (struct TreeNode*) malloc(sizeof(TreeNode));
            node->rightChild->value = value;
        } else {
            insertValue(node->rightChild, value);
        }
    } else {
        if(node->leftChild == NULL) {
            node->leftChild = (struct TreeNode*) malloc(sizeof(TreeNode));
            node->leftChild->value = value;
        } else {
            insertValue(node->leftChild, value);
        }
    }
    return 0;
}

int* inOrderTraversal(TreeNode* node) {
    if(node->leftChild != NULL) inOrderTraversal(node->leftChild);
    printf("%d ", node->value);
    if(node->rightChild != NULL) inOrderTraversal(node->rightChild);
}


int main() {
    TreeNode* tree = malloc(sizeof(TreeNode));
    int nums[] = {16, 42, 23, 4, 15};

    tree->value = 8;

    for(int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        insertValue(tree, nums[i]);
    }

    inOrderTraversal(tree);

}