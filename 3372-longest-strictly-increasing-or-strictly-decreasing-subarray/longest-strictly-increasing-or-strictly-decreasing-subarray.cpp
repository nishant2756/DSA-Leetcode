class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int left = 0;
        for (int right = 1; right < n; ++right) {
            if (nums[right] <= nums[right - 1]) {
                left = right; 
            }
            ans = max(ans, right - left + 1);
        }
        
        left = 0;
        for (int right = 1; right < n; ++right) {
            if (nums[right] >= nums[right - 1]) {
                left = right; 
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
        
    }
};