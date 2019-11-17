class Solution {
public:
    int minDistance(string word1, string word2) {
        const int debug = 0;
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 < len2)
            return minDistance(word2, word1);
        
        if (debug)
            cout << "word1 is " << word1 << endl;
        if (len2 == 0)
            return len1;
        
        int *dp = (int *)malloc(len1 * len2 * sizeof(int));
        memset(dp, -1, len1 * len2 * sizeof(int));
        
        int first = -1;
        char c = word2[0];
        for (int i = 0; i < len1; ++i) {
            if (c == word1[i]) {
                dp[i] = i;
                break;
            }
        }
        if (0 != dp[0]) {
            dp[0] = 1;
            first = 1;
        }
        
        for (int i = 1; i < len2; ++i) {
            char c = word2[i];
            int *last = dp + (i - 1) * len1;
            int *next = dp + i * len1;
            if (debug)
                cout << "check i = " << i << " char = " << c << endl;
            if (first > 0) {
                if (c == word1[0]) {
                    next[0] = first;
                    first = -1;
                    if (debug)
                        cout << "first match 0 " << next[0] << endl;
                } else {
                    ++first;
                }
            }
            for (int j = 0; j < len1; ++j) {
                if (last[j] < 0)
                    continue;
                if (j == len1 - 1) {
                    if (next[j] < 0 || next[j] > last[j] + 1)
                        next[j] = last[j] + 1;
                    continue;
                }
                if (c == word1[j + 1]) {
                    if (next[j + 1] < 0 || next[j + 1] > last[j]) {
                        next[j + 1] = last[j];
                        if (debug)
                            cout << "match at " << j + 1 << " cnt " << next[j + 1] << endl;
                    }
                    continue;
                }
                if (next[j] < 0 || next[j] > last[j] + 1) {
                    next[j] = last[j] + 1;
                    if (debug)
                        cout << "add after " << j << " cnt " << next[j] << endl;
                }
                if (next[j + 1] < 0 || next[j + 1] > last[j] + 1) {
                    next[j + 1] = last[j] + 1;
                    if (debug)
                        cout << "change at " << j + 1 << " cnt " << next[j + 1] << endl;
                }
                int start = j + 1;
                while (++start < len1) {
                    if (c == word1[start])
                        break;
                }
                if (start == len1)
                    continue;
                if (next[start] < 0 || next[start] > last[j] + start - j - 1) {
                    next[start] = last[j] + start - j - 1;
                    if (debug)
                        cout << "skip until " << start << " cnt " << next[start] << " last pos " << j << endl;
                }
            }
        }
        if (debug)
            cout << "end" << endl;
        int min = -1;
        int *last = dp + (len2 - 1) * len1;
        for (int i = 0; i < len1; ++i) {
            if (last[i] < 0)
                continue;
            if (debug)
                cout << "i = " << i << " last " << last[i] << endl;
            if (min < 0 || (last[i] + (len1 - 1 - i) < min)) {
                min = last[i] + (len1 - 1 - i);
            }
        }
        return min;
    }
};
