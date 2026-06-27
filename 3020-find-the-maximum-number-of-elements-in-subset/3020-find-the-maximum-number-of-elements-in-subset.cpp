class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int oneCnt = 0;
        if (cnt.count(1)) {
            oneCnt = cnt[1];
        }

        int ans;
        if (oneCnt % 2 == 1) {
            ans = oneCnt;
        } else {
            ans = oneCnt - 1;
        }

        cnt.erase(1);

        for (pair<long long, int> it : cnt) {
            long long num = it.first;
            int res = 0;
            long long x = num;

            while (cnt.count(x) && cnt[x] > 1) {
                res = res + 2;
                x = x * x;
            }

            if (cnt.count(x)) {
                ans = max(ans, res + 1);
            } else {
                ans = max(ans, res - 1);
            }
        }

        return ans;
    }
};