/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void iterTree(Node *root, vector<int> &res) {
        for (Node *n : root->children)
            iterTree(n, res);
        res.push_back(root->val);
        
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root)
            iterTree(root, res);
        
        return res;
    }
};
