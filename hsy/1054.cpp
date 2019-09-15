class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> nmap;
        for (int n : barcodes)
            ++nmap[n];

        vector<pair<int, int>> ord_vec;
        for (auto mi = nmap.begin(); mi != nmap.end();) {
            int start = 0, end = ord_vec.size();
            int pos = 0;
            while (start < end) {
                if (ord_vec[pos].first > mi->second) {
                    start = pos + 1;
                    pos = (start + end) / 2;
                } else {
                    end = pos;
                    pos = (start + end) / 2;
                }
            }
            ord_vec.insert(ord_vec.begin() + pos, {mi->second, mi->first});
            nmap.erase(mi);
            mi = nmap.begin();
        }

        vector<int> res(barcodes.size());
        int odd = (barcodes.size() + 1) / 2;
        //int even = barcodes.size() - odd;
        int len = ord_vec.size();
        int off = 0;
        for (int i = 0; i < len; ++i) {
            if (odd >= ord_vec[i].first) {
                for (int j = 0; j < ord_vec[i].first; ++j)
                    res[off + j * 2] = ord_vec[i].second;
                odd -= ord_vec[i].first;
                if (odd != 0)
                    off += ord_vec[i].first * 2;
                else
                    off = 0;
            } else if (odd > 0) {
                int last = ord_vec[i].first - odd;
                for (int j = 0; j < odd; ++j)
                    res[off + j * 2] = ord_vec[i].second;
                odd = 0;
                off = 0;
                for (int j = 0; j < last; ++j)
                    res[off + j * 2 + 1] = ord_vec[i].second;
                off += last * 2;
            } else {
                for (int j = 0; j < ord_vec[i].first; ++j)
                    res[off + j * 2 + 1] = ord_vec[i].second;
                off += ord_vec[i].first * 2;
            }
        }
        return res;
    }
};
