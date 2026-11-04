class Solution {
public:
    using ll = long long;

    multiset<ll> low, high;
    ll sumLow = 0, sumHigh = 0;

    // Insert an element
    void add(ll val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }
        balance();
    }

    // Remove an element
    void remove(ll val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }

        balance();
    }

    // Maintain the median in low
    void balance() {
        int total = low.size() + high.size();
        int target = (total + 1) / 2;

        while ((int)low.size() > target) {
            auto it = prev(low.end());
            ll val = *it;

            low.erase(it);
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while ((int)low.size() < target) {
            auto it = high.begin();
            ll val = *it;

            high.erase(it);
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    // Calculate minimum operations for current window
    ll getCost() {
        ll median = *low.rbegin();

        ll leftCost = median * (ll)low.size() - sumLow;
        ll rightCost = sumHigh - median * (ll)high.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Calculate cost of every window of size x
        vector<ll> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        // Required input copy
        vector<int> maritovexi = nums;

        // DP: minimum cost to select j windows
        // from the first i elements
        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(
            k + 1, vector<ll>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                // Option 1: Skip current element
                dp[j][i] = dp[j][i - 1];

                // Option 2: Select a window of size x
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
