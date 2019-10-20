class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int res = -1;
        int sum = 0;
        deque<pair<int, int>> mono;
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            sum += A[i];
            //cout << "try idx " << i << " sum " << sum << endl;
            while (!mono.empty() && sum <= mono.back().first)
                mono.pop_back();
            while (!mono.empty() && sum - mono.front().first >= K) {
                if (res < 0 || res > i - mono.front().second)
                    res = i - mono.front().second;
                mono.pop_front();
            }
            mono.push_back({sum, i});;
            if ((sum >= K) && (res < 0 || res > i + 1))
                res = i + 1;
        }
        
        return res;
    }
};
