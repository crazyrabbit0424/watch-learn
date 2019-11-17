class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        map<int, int> nmap;
        for (auto &v : clips) {
            int s = v[0];
            int e = v[1];
            if (!nmap.count(s) || nmap[s] < e)
                nmap[s] = e;
        }
        int last = 0;
        int next = 1;
        int res = 0;
        while (next <= T) {
            int maxend = -1;
            for (int i = last; i < next; ++i) {
                if (maxend < nmap[i]) {
                    maxend = nmap[i];
                    //cout << "s " << i << " e " << nmap[i] << endl;
                }
            }
            if (maxend < 0)
                return -1;
            last = next;
            next = maxend + 1;
            ++res;
        }
        return res;
    }
};
