#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftLevel = maxDepth(root->left);
    int rightLevel = maxDepth(root->right);

    if (leftLevel > rightLevel)
    {
        return 1 + leftLevel;
    }
    else
    {
        return 1 + rightLevel;
    }
}

/*


*/