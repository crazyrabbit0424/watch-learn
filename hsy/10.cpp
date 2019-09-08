class Solution {
public:
    bool getMatch(string &s, vector<pair<char, bool>> &pat, int &idx) {
        while (!pat.empty()) {
            char c = pat[0].first;
            bool more = pat[0].second;
            if (more) {
                vector<pair<char, bool>> next_pat;
                int next_idx;
                int max = 0;
                if (c) {
                    while ((idx + max < s.length()) && (s[idx + max] == c))
                        ++max;
                } else {
                    max = s.length() - idx;
                }
                //cout << "test c = " << c << " idx(" << idx << ") max(" << max << ")" << endl;
                for (int i = 0; i <= max; ++i) {
                    next_pat = pat;
                    next_pat.erase(next_pat.begin());
                    next_idx = idx + i;
                    bool find = getMatch(s, next_pat, next_idx);
                    if (!find)
                        continue;
                    return true;
                }
                return false;
            } else {
                if (idx >= s.length())
                    return false;
                if (c && s[idx] != c)
                    return false;
                
                pat.erase(pat.begin());
                ++idx;
            }
        }
        
        if (idx == s.length())
            return true;
        else
            return false;
    }
    bool isMatch(string s, string p) {
        if (p.empty()) {
            if (s.empty())
                return true;
            else
                return false;
        }
        
        vector<pair<char, bool>> pat;
        int len = p.length();
        int i = 0;
        while (i < len) {
            bool more = (i < len - 1) ? (p[i + 1] == '*') : false;
            if (p[i] == '.')
                pat.push_back({0, more});
            else
                pat.push_back({p[i], more});
            i += (more ? 2 : 1);
        }
        for (auto s : pat) {
            cout << "pat " << (s.first ? s.first : '.') << " - " << s.second << endl;
        }
        
        int start = 0;
        return getMatch(s, pat, start);
    }
};
