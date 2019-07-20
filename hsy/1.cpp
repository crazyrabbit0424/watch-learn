class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::map<int, std::vector<int>> num_map;
        for (unsigned i = 0; i < nums.size(); ++i)
            num_map[nums[i]].push_back(i);
        for (auto m : num_map) {
            if (target != 2 * m.first) {
                if (num_map.find(target - m.first) != num_map.end()) {
                    res.push_back(m.second[0]);
                    res.push_back(num_map[target - m.first][0]);
                    break;
                }
            }
            else if (m.second.size() > 1) {
                res.push_back(m.second[0]);
                res.push_back(m.second[1]);
                break;
            }
        }
        return res;
    }
};
