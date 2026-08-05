class Solution {
public:
    int countDigitOne(int n) {
       
        if (n <= 0) return 0;
        if (n < 10) return 1;

        // Find highest power of 10 <= n and the number of digits - 1
        long long pow10 = 1;
        int k = 0; // exponent
        while (pow10 * 10 <= n) {
            pow10 *= 10;
            k++;
        }

        int msd = n / pow10;      // Most Significant Digit
        int rem = n % pow10;      // Remainder

        // 1. Ones in lower k digits across all 'msd' complete full-range blocks
        int onesInFullBlocks = msd * k * (pow10 / 10);

        // 2. Ones at the MSD position itself
        int onesInMSD = 0;
        if (msd > 1) {
            onesInMSD = pow10;
        } else if (msd == 1) {
            onesInMSD = rem + 1;
        }

        // 3. Ones in remainder (Recursive Step)
        int onesInRemainder = countDigitOne(rem);

        return onesInFullBlocks + onesInMSD + onesInRemainder;
    }
};