class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        vector<pair<int, int>> mono;
        int len = heights.size();
        for (int i = 0; i < len; ++i) {
            if (mono.empty()) {
                mono.push_back({heights[i], i});
                continue;
            }
            int last = mono.back().first;
            if (last <= heights[i]) {
                if (last < heights[i])
                    mono.push_back({heights[i], i});
                continue;
            }
            int start;
            while (!mono.empty()) {
                auto &first = mono.back();
                if (first.first <= heights[i])
                    break;
                start = first.second;
                int rec = first.first * (i - first.second);
                if (rec > max)
                    max = rec;
                mono.pop_back();
            }
            mono.push_back({heights[i], start});
        }
        while (!mono.empty()) {
            auto &first = mono.back();
            int rec = first.first * (len - first.second);
            if (rec > max)
                max = rec;
            mono.pop_back();
        }
        return max;
    }
};
