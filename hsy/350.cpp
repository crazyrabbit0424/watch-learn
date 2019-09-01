class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nmap;
        vector<int> res;
        for (int n : nums1) {
            if (nmap.find(n) == nmap.end())
                nmap[n] = 1;
            else
                ++nmap[n];
        }
        for (int n : nums2) {
            auto It = nmap.find(n);
            if (It != nmap.end() && It->second > 0) {
                res.push_back(n);
                --nmap[n];
            }
        }
        return res;
    }
};
