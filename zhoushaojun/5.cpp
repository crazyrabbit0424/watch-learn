class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0)
        {
			return s;
		}
        bool dp[len][len];
        int start = 0, end = 0;
		/* 对角 */
        for (int i = 0; i <len; i++)
        {
			dp[i][i] = true;
		}
        for (int right = 1; right < len; right++)
        {
			for (int left = 0; left < right; left++)
            {
				if (s[right]==s[left] && (right-left==1 || dp[left+1][right-1])) 
                {
                    dp[left][right] = true;
                    if (right-left > end-start)
					{
                        start = left; end = right;
                    }
                    continue;
                }
                else
                {
                    dp[left][right] = false;
                }
			}
		}
        return s.substr(start, end-start+1);
    }
};