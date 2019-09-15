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
private:
    int sum;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root)
            return nullptr;
        
        if (!root->left && !root->right) {
            root->val += sum;
            sum = root->val;
            return root;
        }
        
        if (root->right)
            bstToGst(root->right);
        root->val += sum;
        sum = root->val;
        if (root->left)
            bstToGst(root->left);
        
        return root;
    }
};
