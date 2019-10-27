class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        map<int, int> revmap;
        for (auto &cord : points) {
            if (!revmap.count(cord[1]) || revmap[cord[1]] < cord[0])
                revmap[cord[1]] = cord[0];
        }
        
        int res = 0;
        auto it = revmap.rbegin();
        int min;
        while (it != revmap.rend()) {
            ++res;
            min = it->second;
            while (++it != revmap.rend() && min <= it->first) {
                if (min < it->second)
                    min = it->second;
            }
        }
        
        return res;
    }
};
