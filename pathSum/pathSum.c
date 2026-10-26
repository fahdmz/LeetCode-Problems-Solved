#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }

    targetSum -= root->val;

    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

/*
2 -> 4 -> 11 -> NULL


root = [5,4,8,11,null,13,4,7,2,null,null,null,1],
targetSum = 22
Output: true
*/