class Solution {
public:
    void lowerCase(string &s) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] -= ('A' - 'a');
        }
        return;
    }
    void uniformVow(string &s) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            switch (s[i]) {
            default: break;
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                s[i] = 'a';
                break;
            }
        }
        return;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> exact_set;
        map<string, string> case_map;
        map<string, string> vow_map;
        for (string &s : wordlist) {
            string ori = s;
            exact_set.insert(s);
            lowerCase(s);
            if (!case_map.count(s))
                case_map[s] = ori;
            uniformVow(s);
            if (!vow_map.count(s))
                vow_map[s] = ori;
        }
        #if 0
        for (string s : exact_set)
            cout << s << " ";
        cout << endl;
        for (auto &p : case_map)
            cout << p.first << " ";
        cout << endl;
        for (auto &p : vow_map)
            cout << p.first << " ";
        cout << endl;
        #endif
        for (string &s : queries) {
            if (exact_set.count(s))
                continue;
            lowerCase(s);
            if (case_map.count(s)) {
                s = case_map[s];
                continue;
            }
            uniformVow(s);
            if (vow_map.count(s))
                s = vow_map[s];
            else
                s = "";
        }
        return queries;
    }
};
