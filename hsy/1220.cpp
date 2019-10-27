class Solution {
public:
    int countVowelPermutation(int n) {
        unsigned long long last[5] = {1, 1, 1, 1, 1};
        while (--n > 0) {
            unsigned long long next[5] = {0, 0, 0, 0, 0};
            next[1] += last[0]; // a->e
            
            next[0] += last[1]; // e->a
            next[2] += last[1]; // e->i
            
            next[0] += last[2]; // i->a
            next[1] += last[2]; // i->e
            next[3] += last[2]; // i->o
            next[4] += last[2]; // i->u
            
            next[2] += last[3]; // o->i
            next[4] += last[3]; // o->u
            
            next[0] += last[4]; // u->a
            memcpy(last, next, 5 * sizeof(unsigned long long));
            for (int i = 0; i < 5; ++i) {
                if (last[i] >= ((unsigned long long)1 << 60))
                    last[i] = last[i] % 1000000007;
            }
        }
        unsigned long long total = 0;
        for (int i = 0; i < 5; ++i)
            total += last[i];
        return total % 1000000007;
    }
};
