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
    TreeNode *root;
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return root;
        TreeNode *node = new TreeNode(nums[0]);
        nums.erase(nums.begin());
        if (!root) {
            root = node;
        } else if (root->val < node->val) {
            node->left = root;
            root = node;
        } else {
            TreeNode *parent = root;
            while (parent->right && parent->right->val > node->val)
                parent = parent->right;
            TreeNode *temp = parent->right;
            parent->right = node;
            node->left = temp;
        }
        return constructMaximumBinaryTree(nums);
    }
};
