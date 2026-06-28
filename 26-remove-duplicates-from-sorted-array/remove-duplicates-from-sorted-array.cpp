class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int officer = 0;
        int rev = 1 ;
        int cm = 1;
        int n = nums.size();

        while(cm<n){
            if(nums[cm] == nums[cm-1]){
                cm++;
                continue;
            }

            nums[officer + 1] = nums[cm];
            officer++;
            rev++;
            cm++; 

        }
        return rev;

        
    }
};