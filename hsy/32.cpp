class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> pos;
        std::map<int, int> pos_map;
        int max_match = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                pos.push(i);
            } else if (pos.size()) {
                int left = pos.top();
                pos_map[i] = left;
                pos.pop();
                int this_match = (i - left + 1);
                left--;
                while (left > 0) {
                    auto map = pos_map.find(left);
                    if (map == pos_map.end())
                        break;
                    this_match += (map->first - map->second + 1);
                    left = map->second - 1;
                }
                max_match = (max_match > this_match) ? max_match : this_match;
            }
        }
        return max_match;
    }
};
