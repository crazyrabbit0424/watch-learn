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
    TreeNode* recoverFromPreorder(string &S, int &idx) {
        int len = S.length();
        int val = 0;
        int i = 0;
        for (;  i < len; ++i) {
            if (S[i] >= '0' && S[i] <= '9')
                val = val * 10 + (int)(S[i] - '0');
            else
                break;
        }
        TreeNode *node = new TreeNode(val);
        S.erase(0, i);
        
        if (len == i) {
            idx = -1;
            return node;
        }
        
        int nextidx = 0;
        while (S[nextidx] == '-')
            ++nextidx;
        S.erase(0, nextidx);
        //cout << "first: " << idx << " [" << val << "]" << " nextidx " << nextidx << " string " << S << endl;
        if (idx + 1 == nextidx) {
            node->left = recoverFromPreorder(S, nextidx);
            //cout << "second: " << idx << " [" << val << "]" << " nextidx " << nextidx << " string " << S << endl;
            if (nextidx > 0 && idx + 1 == nextidx) {
                node->right = recoverFromPreorder(S, nextidx);
            }
        }
        
        idx = nextidx;
        return node;
    }
    TreeNode* recoverFromPreorder(string S) {
        int init = 0;
        return recoverFromPreorder(S, init);
    }
};
