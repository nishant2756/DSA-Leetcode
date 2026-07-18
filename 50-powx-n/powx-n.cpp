class Solution {
public:
    double myPow(double x, int n) {
       
        long long N = n; 
        
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double cP = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                ans = ans * cP;
            }
            
            
            cP = cP * cP;
            N = N / 2;
        }
        
        return ans;
    }
};