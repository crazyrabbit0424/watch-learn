class Solution {
    pair<int, int> res;
public:
    string longestPalindrome(string s) {
        res.first = res.second = 0;
        int cnt = s.length();
        for (int i = 0; i < cnt; ++i) {
            for (int j = 1; j < 3; ++j) {
                if (i + j >= cnt)
                    break;
                if (s[i] == s[i + j]) {
                    int start = i, end = i + j;
                    while (start >= 0 && end < cnt && s[start] == s[end]) {
                        --start;
                        ++end;
                    }
                    ++start;
                    --end;
                    if (res.second - res.first < end - start) {
                        res.first = start;
                        res.second = end;
                    }
                }
            }
        }
        return s.substr(res.first, res.second - res.first + 1);
    }
};
