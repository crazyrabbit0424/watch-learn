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
    bool getValidRange(TreeNode *node, std::pair<int, int> &range) {
        std::pair<int, int> l_range;
        std::pair<int, int> r_range;
        if (node->left) {
            if (!getValidRange(node->left, l_range))
                return false;
            if (node->val <= l_range.second)
                return false;
            range.first = l_range.first;
        } else {
            range.first = node->val;
        }
        if (node->right) {
            if(!getValidRange(node->right, r_range))
                return false;
            if (node->val >= r_range.first)
                return false;
            range.second = r_range.second;
        } else {
            range.second = node->val;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        std::pair<int, int> range;
        return getValidRange(root, range);
    }
};
