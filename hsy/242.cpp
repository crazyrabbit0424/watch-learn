class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map;
        for (char c : s) {
            ++map[c];
        }
        for (char c : t) {
            auto m = map.find(c);
            if (m == map.end())
                return false;
            if (--m->second == 0)
                map.erase(m);
        }
        return map.empty();
    }
};
