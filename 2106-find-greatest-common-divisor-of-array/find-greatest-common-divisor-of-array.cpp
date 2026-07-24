class Solution {
public:
    int findGCD(vector<int>& nums) {

        int minVal = *std::min_element(nums.begin(), nums.end());
        int maxVal = *std::max_element(nums.begin(), nums.end());

        return gcd(minVal, maxVal);
        
    }
};