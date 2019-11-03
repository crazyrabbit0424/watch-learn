class Solution{
    public:
    string removeDuplicates(string s, int k){
        vector<pair<char, int>> st;
        string sret;
        int cnt = 0;

        for (auto & i : s)
        {
            if ((!st.empty()) && (st.back().first == i))
            {
                st.back().second()++;
                if (st.back().second == k)
                {
                    st.pop_back();
                }
                else
                {
                    st.push_back({i, 1});
                }
            }
        }

        for (auto & i : st)
        {
            cnt = i.second;
            while (cnt--)
            {
                res += i.first;
            }
        }

        return sret;
    }
}
