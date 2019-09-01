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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        
        vector<TreeNode *> next;
        next.push_back(root);
        while (!next.empty()) {
            vector<int> level;
            int size = next.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = next[i];
                level.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }
            res.push_back(level);
            next.erase(next.begin(), next.begin() + size);
        }
        return res;
    }
};
