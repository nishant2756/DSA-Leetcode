class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int count[10] = {0};
        for (int d : digits) count[d]++;

        function<void(int, int)> solve = [&](int num, int len) {
            if (len == 3) {
                if (num % 2 == 0) res.insert(num);
                return;
            }
            for (int i = 0; i < 10; ++i) {
                if ((len == 0 && i == 0) || count[i] == 0) continue;
                count[i]--;
                solve(num * 10 + i, len + 1);
                count[i]++;
            }
        };

        solve(0, 0);
        return {res.begin(), res.end()};
        
    }
};