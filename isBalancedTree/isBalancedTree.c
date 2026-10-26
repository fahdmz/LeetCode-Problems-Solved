#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}