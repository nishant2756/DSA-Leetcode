class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;

        long long totalCommas = 0;
        long long threshold = 1000; // 10^3, 10^6, 10^9, 10^12, ...

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);

            // Avoid 64-bit integer overflow
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return totalCommas;
    }

    // Overload for [left, right] range if needed:
    long long countCommasInRange(long long left, long long right) {
        if (left > right) return 0;
        return countCommas(right) - countCommas(left - 1);
        
    }
};