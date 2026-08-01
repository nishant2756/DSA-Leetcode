class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return maxScoreDiff(nums, 0, nums.size() - 1) >= 0;
    }

private:
    int maxScoreDiff(const std::vector<int>& nums, int left, int right) {
        // Base case: only one element left
        if (left == right) {
            return nums[left];
        }

        // Option 1: Take the left element
        int pickLeft = nums[left] - maxScoreDiff(nums, left + 1, right);

        // Option 2: Take the right element
        int pickRight = nums[right] - maxScoreDiff(nums, left, right - 1);

        // Current player chooses the option that yields maximum advantage
        return max(pickLeft, pickRight);
    }
};