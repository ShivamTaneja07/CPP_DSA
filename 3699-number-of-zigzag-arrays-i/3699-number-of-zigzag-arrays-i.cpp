class Solution {
public:
    int mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        vector<long long> up(m, 0), down(m, 0);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m, 0), newDown(m, 0);

            long long pref = 0;

            for (int i = 0; i < m; i++) {
                newUp[i] = pref;
                pref = (pref + down[i]) % mod;
            }

            long long suff = 0;

            for (int i = m - 1; i >= 0; i--) {
                newDown[i] = suff;
                suff = (suff + up[i]) % mod;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % mod;
        }

        return ans;
    }
};