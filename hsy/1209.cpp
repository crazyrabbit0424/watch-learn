class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> cvec;
        int len = s.length();
        char last = s[0];
        int cnt = 0;
        for (char c : s) {
            if (c == last)
                ++cnt;
            else {
                if (cnt >= k)
                    cnt = cnt % k;
                if (cnt > 0) {
                    cvec.push_back({last, cnt});
                    last = c;
                    cnt = 1;
                } else if (!cvec.empty()) {
                    auto &p = cvec.back();
                    if (p.first == c) {
                        cvec.pop_back();
                        last = p.first;
                        cnt = p.second + 1;
                    } else {
                        last = c;
                        cnt = 1;
                    }
                } else {
                    last = c;
                    cnt = 1;
                }
            }
        }
        if (cnt >= k)
            cnt = cnt % k;
        if (cnt > 0)
            cvec.push_back({last, cnt});
        
        string res;
        for (auto &p : cvec)
            res.insert(res.end(), p.second, p.first);
        return res;
    }
};
