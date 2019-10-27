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
    TreeNode *last;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root->right)
            root->right = increasingBST(root->right);
        else
            root->right = last;
        last = root;
        TreeNode *left = root->left;
        root->left = nullptr;
        return left ? increasingBST(left) : root;
    }
};
