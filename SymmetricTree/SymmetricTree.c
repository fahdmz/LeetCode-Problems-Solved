#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;

    bool krk = isSymmetricHelper(left, right);

    return krk;
}

bool isSymmetricHelper(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
    {
        return false;
    }

    if (left->val == right->val)
    {
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
    return false;
}

/*

         2
        / \
       3.  4


*/