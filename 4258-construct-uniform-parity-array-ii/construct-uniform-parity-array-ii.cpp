class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = INT_MAX;
        int odd_count = 0;

        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                odd_count++;
            }
        }
        // Returns true if all numbers are already even,
        // or if the minimum element is odd.
        return (odd_count == 0 || min_val % 2 != 0);

    }
};