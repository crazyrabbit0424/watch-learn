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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int cnt = 1;
        if (root->left)
            cnt += countNodes(root->left);
        if (root->right)
            cnt += countNodes(root->right);
        return cnt;
    }
};
