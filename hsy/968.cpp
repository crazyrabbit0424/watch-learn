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
    int num;
public:
    bool needMarkNode(TreeNode *node) {
        bool mark = false;
        if (!node)
            return false;
        if (node->left)
            mark |= needMarkNode(node->left);
        if (node->right)
            mark |= needMarkNode(node->right);
        if (mark) {
            num++;
            node->val = 1;
            return false;
        } else {
            bool childmark = (node->left && node->left->val) || (node->right && node->right->val);
            return !childmark;
        }
    }
    int minCameraCover(TreeNode* root) {
        num = 0;
        if (needMarkNode(root))
            num++;
        return num;
    }
};
