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
    int longest;
public:
    int findLongestPath(TreeNode *root) {
        if (!root || (!root->left && !root->right))
            return 0;
        
        int left = 0, right = 0;
        if (root->left) {
            left = findLongestPath(root->left);
            if (root->val == root->left->val)
                ++left;
            else
                left = 0;
        }
        
        if (root->right) {
            right = findLongestPath(root->right);
            if (root->val == root->right->val)
                ++right;
            else
                right = 0;
        }
        
        if (longest < left + right)
            longest = left + right;
        return (left > right ? left : right);
    }
    int longestUnivaluePath(TreeNode* root) {
        longest = 0;
        findLongestPath(root);
        return longest;
    }
};
