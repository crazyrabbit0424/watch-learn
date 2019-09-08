class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lengthA = A.size();
        int lengthB = B.size();
        if (lengthA > lengthB)
            return findLength(B, A);
        
        int res = 0;
        vector<int> start;
        for (int i = lengthB - 1; i >= 0; --i) {
            if (res > i)
                break;
            start.clear();
            for (int j = lengthA - 1; j >= 0; --j) {
                if (res > j)
                    break;
                if (B[i] != A[j])
                    continue;
                int len = 1;
                int min = i > j ? j : i;
                while ((min > 0) && (B[i - len] == A[j - len])) {
                    ++len;
                    --min;
                }
                //j -= (len - 1);
                if (len > res)
                    res = len;
            }
        }
        
        return res;
    }
};
