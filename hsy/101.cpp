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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if ((!left && right) || (left && !right))
            return false;
        if (!left && !right)
            return true;
        if (left->val != right->val)
            return false;
        if (!isSymmetric(left->left, right->right))
            return false;
        if (!isSymmetric(left->right, right->left))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
