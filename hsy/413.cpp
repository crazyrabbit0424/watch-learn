class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), cnt = 0;
        bool find = false;
        int diff, start;
        for (int i = 0; i < size - 2; ++i) {
            if (!find && (A[i] + A[i + 2] == A[i + 1] * 2)) {
                find = true;
                diff = A[i + 1] - A[i];
                start = i;
            } else if (find && (A[i] + diff != A[i + 1])) {
                find = false;
                int max = i - start - 1;
                cnt += (1 + max) * max / 2;
            }
        }
        if (find) {
            int max = size - 3 - start - 1;
            for (int i = size - 2; i < size; ++i) {
                if (A[i] == A[i - 1] + diff)
                    ++max;
            }
            cnt += (1 + max) * max / 2;
        }
        return cnt;
    }
};
