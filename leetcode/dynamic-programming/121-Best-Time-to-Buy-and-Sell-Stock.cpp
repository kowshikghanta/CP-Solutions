class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int max = 0;
        for (std::size_t j = 0; j < n; j++) {
            if (prices[j] > prices[i]) {
                max = std::max(max, prices[j] - prices[i]);
            } else {
                i = j;
            }
        }

        return max;
    }
};