class Solution {
public:
    int getCoins(vector<int> &coins, int *pn, int amount) {
        if (pn[amount - 1] > 0)
            return pn[amount - 1];
        
        int res = -1;
        for (int n : coins) {
            if (amount < n)
                continue;
            int last = pn[amount - 1 - n];
            if (last < 0)
                continue;
            if (last == 0)
                last = getCoins(coins, pn, amount - n);
            if ((last > 0) && (res == -1 || res > last + 1))
                res = last + 1;
        }
        
        pn[amount - 1] = res;
        return res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if (!amount)
            return 0;

        int *pn = new int[amount];
        memset(pn, 0, amount * sizeof(int));
        for (int n : coins) {
            if (n <= amount)
                pn[n - 1] = 1;
        }
        
        int res = getCoins(coins, pn, amount);
        
        delete[] pn;
        return res;
    }
};
