class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       stack<int> st; // stores indices
        
        for (int i = 0; i < prices.size(); ++i) {
            // Apply discount to all previous items that are >= current item
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return prices;
        
    }
};