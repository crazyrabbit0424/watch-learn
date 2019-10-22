class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> cmap;
        for (char c : tasks)
            ++cmap[c];
        vector<int> vec;
        for (auto &p : cmap)
            vec.push_back(p.second);
        sort(vec.begin(), vec.end());
        vector<int>::iterator last = vec.end();
        --last;
        int buckets = *last - 1;
        int res = buckets * (n + 1) + 1;
        if (last != vec.begin()) {
            while (last != vec.begin() && *(--last) > buckets)
                ++res;
        }
        if (res < tasks.size())
            res = tasks.size();
        return res;
    }
};
