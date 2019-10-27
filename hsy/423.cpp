class Solution {
public:
    string originalDigits(string s) {
        map<char, int> cmap;
        for (char c : s)
            ++cmap[c];
        // z - zero
        // w - two
        // u - four
        // x - six
        // one(o) - three(r) - five(f) - seven(v) - eight(t) - nine
        string res;
        int cnt[10] = {0};
        
        cnt[0] = cmap['z'];
        cnt[1] = cmap['o'] - cmap['z'] - cmap['w'] - cmap['u'];
        cnt[2] = cmap['w'];
        cnt[3] = cmap['r'] - cmap['z'] - cmap['u'];
        cnt[4] = cmap['u'];
        cnt[5] = cmap['f'] - cmap['u'];
        cnt[6] = cmap['x'];
        cnt[7] = cmap['v'] - cnt[5];
        cnt[8] = cmap['t'] - cnt[2] - cnt[3];
        cnt[9] = (cmap['n'] - cnt[1] - cnt[7]) / 2;
        #if 0
        for (int i = 0; i < 10; ++i)
            cout << cnt[i] << " ";
        cout << endl;
        #endif
        res.insert(res.end(), cnt[0], '0');
        res.insert(res.end(), cnt[1], '1');
        res.insert(res.end(), cnt[2], '2');
        res.insert(res.end(), cnt[3], '3');
        res.insert(res.end(), cnt[4], '4');
        res.insert(res.end(), cnt[5], '5');
        res.insert(res.end(), cnt[6], '6');
        res.insert(res.end(), cnt[7], '7');
        res.insert(res.end(), cnt[8], '8');
        res.insert(res.end(), cnt[9], '9');
        return res;
    }
};
