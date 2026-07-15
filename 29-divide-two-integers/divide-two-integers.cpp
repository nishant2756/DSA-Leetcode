class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int a = dividend;
        long long int b = divisor;

        if (a==INT_MIN && b==-1){
            return INT_MAX;
        }
        long long int ans = a/b;
        return ans;
    }
};