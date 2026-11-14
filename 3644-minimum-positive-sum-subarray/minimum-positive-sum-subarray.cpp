class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

         int n = nums.size();

        // prefix[i] = sum of first i elements
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        // har possible length len (l se r tak) try karo
        for (int len = l; len <= r; len++) {
            // length len ka har window check karo
            for (int i = 0; i + len <= n; i++) {
                int sum = prefix[i + len] - prefix[i];
                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};