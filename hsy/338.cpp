class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        
        res.push_back(0);
        if (num == 0)
            return res;
        res.push_back(1);
        if (num == 1)
            return res;
        
        for (int i = num >> 1; i; i = i >> 1) {
            int size = res.size();
            vector<int> dup = res;
            res.insert(res.end(), dup.begin(), dup.end());
            for (int j = 0; j < size; ++j)
                ++res[j + size];
        }
        
        res.erase(res.begin() + num + 1, res.end());
        return res;
    }
};
