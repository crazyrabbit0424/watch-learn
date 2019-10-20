class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        int nums = M.size();
        set<int> relations;
        
        while (relations.size() < nums) {
            vector<int> worklist;
            for (int i = 0; i < nums; ++i) {
                if (!relations.count(i)) {
                    worklist.push_back(i);
                    relations.insert(i);
                    ++res;
                    break;
                }
            }
            
            while (!worklist.empty()) {
                int n = worklist.back();
                worklist.pop_back();
                vector<int> &one_relation = M[n];
                for (int i = 0; i < nums; ++i) {
                    int connect = one_relation[i];
                    if (connect && !relations.count(i)) {
                        relations.insert(i);
                        worklist.push_back(i);
                    }
                }
            }
        }
        
        return res;
    }
};
