class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int min = 0;
        map<int, set<int>> xmap;
        map<int, set<int>> ymap;
        for (auto &p : points) {
            int x = p[0];
            int y = p[1];
            xmap[x].insert(y);
            ymap[y].insert(x);
        }
        for (auto &p : xmap) {
            int x0 = p.first;
            auto &vline = p.second;
            for (auto vit = vline.begin(); vit != vline.end(); ++vit) {
                int y0 = *vit;
                auto &hline = ymap[y0];
                auto hit = hline.begin();
                while (*hit != x0)
                    ++hit;
                for (auto viit = vline.find(y0); ++viit != vline.end();) {
                    int y1 = *viit;
                    for (auto hiit = hline.find(x0); ++hiit != hline.end();) {
                        int x1 = *hiit;
                        if (xmap[x1].count(y1)) {
                            int sqrt = (y1 - y0) * (x1 - x0);
                            if (min == 0 || sqrt < min)
                                min = sqrt;
                        }
                    }
                }
            }
        }
        return min;
    }
};
