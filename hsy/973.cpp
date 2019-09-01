class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size() < 2)
            return points;
        
        int i = 1, j = points.size() - 1;
        vector<int> &mid = points[0];
        int fm = mid.front() * mid.front();
        int sm = mid.back() * mid.back();
        while (i < j) {
            int fi, si, fj, sj;
            bool find = false;
            while (i < j) {
                fi = points[i].front();
                si = points[i].back();
                if (fi * fi - fm > sm - si * si)
                    break;
                ++i;
            }
            while (i < j) {
                fj = points[j].front();
                sj = points[j].back();
                if (fj * fj - fm < sm - sj * sj) {
                    find = true;
                    break;
                }
                --j;
            }
            if (find && (fi * fi - fj * fj > sj * sj - si * si)) {
                vector<int> &pi = points[i];
                pi[0] = fj;
                pi[1] = sj;
                vector<int> &pj = points[j];
                pj[0] = fi;
                pj[1] = si;
            }
        }
        int fi = points[i].front(), si = points[i].back();
        if (fi * fi - fm < sm - si * si) {
            vector<int> &pi = points[i];
            pi[0] = points[0].front();
            pi[1] = points[0].back();
            vector<int> &p0 = points[0];
            p0[0] = fi;
            p0[1] = si;
        }
        if (i > K) {
            points.erase(points.begin() + i, points.end());
            return kClosest(points, K);
        }
        vector<vector<int>> res;
        res.insert(res.end(), points.begin(), points.begin() + i);
        if (K > i) {
            points.erase(points.begin(), points.begin() + i);
            vector<vector<int>> next = kClosest(points, K - i);
            res.insert(res.end(), next.begin(), next.end());
        }
        return res;
    }
};
