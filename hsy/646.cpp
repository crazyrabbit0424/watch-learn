class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        map<int, pair<int, int>> endmap;
        for (auto &v : pairs) {
            int s = v[0];
            int e = v[1];
            if (!endmap.count(e) || endmap[e].first < s)
                endmap[e] = {s, 1};
        }
        int max = 0;
        for (auto it = next(endmap.begin()); it != endmap.end(); ++it) {
            auto &p = it->second;
            int thiscnt = 0;
            for (auto iit = endmap.begin(); iit != it; ++iit) {
                int lastend = iit->first;
                int lastcnt = iit->second.second;
                // if last_end < this_start && this_cnt < last_cnt
                if (lastend < p.first && thiscnt < lastcnt)
                    thiscnt = lastcnt;
            }
            p.second += thiscnt;
            //cout << "test end " << it->first << " cnt " << p.second << endl;
            if (p.second > max)
                max = p.second;
        }
        return max;
    }
};
