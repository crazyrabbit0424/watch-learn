/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(val1, val2) (((val1) > (val2)) ? (val1) : (val2))
int sum = 0;
int calMax(struct TreeNode *root)
{
    int rootLeft = 0;
    int rootRight = 0;
    
    if (NULL == root)
    {
        return 0;
    }
    
    rootLeft = calMax(root->left);
    rootLeft = MAX(rootLeft, 0);
    
    rootRight = calMax(root->right);
    rootRight = MAX(rootRight, 0);
    
    sum = MAX(sum, root->val + rootLeft + rootRight);
    
    return MAX(rootLeft, rootRight) + root->val;
}

int maxPathSum(struct TreeNode* root){
    sum = root->val;
    
    calMax(root);
    
    return sum;
}