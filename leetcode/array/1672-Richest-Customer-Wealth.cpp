class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int max = 0;

        for (std::size_t i = 0; i < m; i++) {
            int cur = 0;
            for (std::size_t j = 0; j < n; j++) {
                cur += accounts[i][j];
            }
            max = std::max(max, cur);
        }

        return max;
    }
};