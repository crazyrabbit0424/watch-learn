class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> preds;
        map<int, set<int>> succs;
        int len = prerequisites.size();
        for (int i = 0; i < len; ++i) {
            vector<int> &edge = prerequisites[i];
            preds[edge[0]].insert(edge[1]);
            succs[edge[1]].insert(edge[0]);
        }
        
        vector<int> worklist;
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (!preds.count(i)) {
                ++cnt;
                worklist.push_back(i);
                cout << "add " << i << endl;
            }
        }
        
        while (!worklist.empty()) {
            int next = worklist.back();
            worklist.pop_back();
            set<int> &nextedge = succs[next];
            for (int p : nextedge) {
                preds[p].erase(next);
                if (preds[p].empty()) {
                    ++cnt;
                    worklist.push_back(p);
                    cout << "add " << p << endl;
                }
            }
        }
        
        return cnt == numCourses;
    }
};
