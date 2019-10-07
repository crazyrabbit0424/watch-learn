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
    map<int, int> inmap;
    set<int> inset;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int idx, int pidx) {
        int nums = preorder.size();
        int val = preorder[idx];
        int inidx = inmap[val];
        inset.insert(idx);
        
        TreeNode *node = new TreeNode(val);
        
        if (idx + 1 < nums) {
            int left = preorder[idx + 1];
            if (inmap[left] < inidx)
                node->left = buildTree(preorder, inorder, idx + 1, idx);
        }
        
        int next = 0;
        for (; next < nums; ++next) {
            if (!inset.count(next))
                break;
        }
        //cout << "get next " << next << " current " << idx << endl;
        if ((next < nums) && (pidx < 0 || inmap[preorder[pidx]] > inmap[preorder[next]])) {
            //cout << "right tree: current = " << idx << " next = " << next << endl;
            node->right = buildTree(preorder, inorder, next, pidx);
        }
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int nums = preorder.size();
        if (nums == 0)
            return nullptr;
        for (int i = 0; i < nums; ++i)
            inmap[inorder[i]] = i;
        
        return buildTree(preorder, inorder, 0, -1);
    }
};
