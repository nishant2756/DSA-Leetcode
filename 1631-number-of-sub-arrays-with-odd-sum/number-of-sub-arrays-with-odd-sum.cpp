class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int even = 1, odd = 0;   // counts of prefix sums by parity (empty prefix is even)
        int parity = 0;          // parity of current prefix sum

        for (int x : arr) {
            parity = (parity + (x & 1)) & 1;

            if (parity == 1) {
                result += even;  // odd prefix - earlier even prefix = odd sum
                odd++;
            } else {
                result += odd;   // even prefix - earlier odd prefix = odd sum
                even++;
            }
            result %= MOD;
        }
        return (int)result;
    }
};