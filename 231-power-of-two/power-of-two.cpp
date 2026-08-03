class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        // Bitwise AND trick
        return (n & (n - 1)) == 0;
        
    }
};