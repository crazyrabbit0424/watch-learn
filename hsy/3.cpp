class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> smap;
        int len = s.length();
        int res = 0, start = 0, next = 0;
        for (int i = 0; i < len; ++i) {
            auto old = smap.find(s[i]);
            if ((old == smap.end()) || old->second < start)
                smap[s[i]] = i;
            else {
                next = i + 1;
                if (i - start > res)
                    res = i - start;
                start = old->second + 1;
                old->second = i;
            }
        }
        if ((next != len) && (len - start > res))
            res = len - start;
        return res;
    }
};
