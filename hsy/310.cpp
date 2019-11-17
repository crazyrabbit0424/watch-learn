class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (edges.empty()) {
            res.push_back(0);
            return res;
        }
        
        map<int, set<int>> tree;
        for (auto &v : edges) {
            int first = v[0];
            int second = v[1];
            tree[first].insert(second);
            tree[second].insert(first);
        }
        
        while (tree.size() > 2) {
            vector<pair<int, int>> worklist;
            for (auto &p : tree) {
                if (p.second.size() > 1)
                    continue;
                worklist.push_back({*p.second.begin(), p.first});
            }
            for (auto &p : worklist) {
                tree[p.first].erase(p.second);
                tree.erase(p.second);
            }
            //cout << tree.size() << endl;
        }
        
        for (auto &p : tree)
            res.push_back(p.first);
        return res;
    }
};
