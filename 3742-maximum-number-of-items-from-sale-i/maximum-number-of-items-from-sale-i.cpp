class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int pmin = 1e9;
        for (int i = 0; i < n; i++)
            pmin = min(pmin, items[i][1]);

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeCount = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % factor == 0)
                    freeCount++;
            }

            int value = 1 + freeCount;

            for (int c = budget; c >= price; c--)
                dp[c] = max(dp[c], dp[c - price] + value);
        }

        int ans = 0;
        for (int c = 0; c <= budget; c++)
            ans = max(ans, dp[c] + (budget - c) / pmin);

        return ans;
        
    }
};