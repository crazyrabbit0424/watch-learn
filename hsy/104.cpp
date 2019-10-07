/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        int left_depth = 0;
        int right_depth = 0;
        if (root->left)
            left_depth = maxDepth(root->left);
        if (root->right)
            right_depth = maxDepth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
};
