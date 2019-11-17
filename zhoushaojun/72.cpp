class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int ret = 0;
        int pt[len1 + 1][len2 + 1];

        for (int i = 0; i <= len1; i++)
        {
            pt[i][0] = i;
        }

        for (int j = 0; j <= len2; j++)
        {
            pt[0][j] = j;
        }

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    pt[i][j] = pt[i - 1][j - 1];
                }
                else
                {
                    pt[i][j] = min(pt[i-1][j-1], min(pt[i-1][j], pt[i][j-1]))+1;
                }
            }
        }
        
        ret = pt[len1][len2];

        return ret;
    }
};