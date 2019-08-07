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
    int getSinglePathSum(TreeNode *node) {
        int left_sum = 0, right_sum = 0;
        if (!node)
            return 0;
        if (node->left)
            left_sum = getSinglePathSum(node->left);
        left_sum = (left_sum < 0) ? 0 : left_sum;
        if (node->right)
            right_sum = getSinglePathSum(node->right);
        right_sum = (right_sum < 0) ? 0 : right_sum;
        int node_sum = left_sum + right_sum + node->val;
        sum = (sum > node_sum) ? sum : node_sum;
        return (left_sum > right_sum) ? left_sum + node->val : right_sum + node->val;
    }
    int maxPathSum(TreeNode* root) {
        sum = root->val;
        getSinglePathSum(root);
        return sum;
    }
};
