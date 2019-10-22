class Solution {
public:
    struct TierNode {
        TierNode *next;
        TierNode *child;
        char c;
        int len;
        TierNode(char ch, int length) {
            next = nullptr;
            child = nullptr;
            c = ch;
            len = length;
        }
    };
    int DFS(TierNode *root) {
        int res = 0;
        if (root->child) {
            res += DFS(root->child);
            if (root->next)
                res += DFS(root->next);
        } else {
            res += root->len + 1;
            if (root->next)
                res += DFS(root->next);
        }
        return res;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        TierNode *root = nullptr;
        
        for (string &s : words) {
            TierNode *node = root;
            TierNode *parent = nullptr;
            for (int i = s.length() - 1; i >= 0; --i) {
                while (node) {
                    if (node->c == s[i])
                        break;
                    node = node->next;
                }
                if (!node) {
                    node = new TierNode(s[i], (parent ? parent->len + 1 : 1));
                    if (parent) {
                        node->next = parent->child;
                        parent->child = node;
                    } else {
                        node->next = root;
                        root = node;
                    }
                }
                parent = node;
                node = node->child;
            }
        }
        
        res += DFS(root);
        return res;
    }
};
