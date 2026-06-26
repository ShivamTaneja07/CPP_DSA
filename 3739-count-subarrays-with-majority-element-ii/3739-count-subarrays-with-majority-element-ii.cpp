class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Frequency array for prefix sums
        vector<int> pre(2 * n + 1, 0);

        pre[n] = 1;          // Initial prefix sum = 0
        int cnt = n;         // Offset index
        long long ans = 0;
        long long presum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                presum += pre[cnt];
                cnt++;
                pre[cnt]++;
            } else {
                cnt--;
                presum -= pre[cnt];
                pre[cnt]++;
            }

            ans += presum;
        }

        return ans;
    }
};