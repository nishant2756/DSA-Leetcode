class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

        int n = nums.size();
        int midd = nums[n/2];

        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i] == midd){
                count++;
            }
            
        }
        return count == 1;
        
    }
};