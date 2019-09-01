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
    int getKth(TreeNode *root, int &k) {
        int res;
        if (root->left)
            res = getKth(root->left, k);
        if (k == 0)
            return res;
        if (--k == 0)
            return root->val;
        if (root->right)
            res = getKth(root->right, k);
        if (k == 0)
            return res;
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        return getKth(root, k);
    }
};
