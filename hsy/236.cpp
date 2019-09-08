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
    bool findAncestor(TreeNode *root, TreeNode *child, vector<TreeNode *> &anc) {
        if (root == child) {
            anc.push_back(root);
            return true;
        }
        
        if (root->left && findAncestor(root->left, child, anc)) {
            anc.push_back(root);
            return true;
        }
        
        if (root->right && findAncestor(root->right, child, anc)) {
            anc.push_back(root);
            return true;
        }
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> anc_p;
        vector<TreeNode *> anc_q;
        
        findAncestor(root, p, anc_p);
        findAncestor(root, q, anc_q);
        
        TreeNode *res;
        while (!anc_p.empty() && !anc_q.empty()) {
            if (anc_p.back() != anc_q.back())
                break;
            res = anc_p.back();
            anc_p.pop_back();
            anc_q.pop_back();
        }
        
        return res;
    }
};
