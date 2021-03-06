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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);

        return root;
    }
}
