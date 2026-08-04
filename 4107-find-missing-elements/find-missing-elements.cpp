class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        // Find the minimum and maximum bounds in the array
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // Insert all numbers into an unordered_set for O(1) lookup
        unordered_set<int> present(nums.begin(), nums.end());
        
        vector<int> missing;

        // Iterate through the full range [minVal, maxVal]
        for (int i = minVal; i <= maxVal; ++i) {
            if (present.find(i) == present.end()) {
                missing.push_back(i);
            }
        }

        return missing;
        
    }
};