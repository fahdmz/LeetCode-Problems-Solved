#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderHelper(struct TreeNode *root, int *result, int *index)
{
    if (root == NULL)
        return;

    result[*index] = root->val;
    (*index)++;

    preorderHelper(root->left, result, index);
    preorderHelper(root->right, result, index);
}
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *result = malloc(100 * sizeof(int));
    *returnSize = 0;

    preorderHelper(root, result, returnSize);
    return result;
}