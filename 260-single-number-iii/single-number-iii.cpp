class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            ans ^= num;
        }
        int diff = ans & -(unsigned int) ans;

        int num1 = 0;
        int num2 = 0;
        for (int num : nums){
            if((num & diff)== 0){
                num1 ^= num;
            }else{
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};