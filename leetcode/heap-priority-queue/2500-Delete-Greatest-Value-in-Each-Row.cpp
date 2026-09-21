class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (vector<int>& i: grid) {
            std::sort(i.begin(), i.end());
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int maximum = -1;
            for (int j = 0; j < m; j++) {
                maximum = std::max(maximum, grid[j][i]);
            }
            ans += maximum;
        }

        return ans;
    }
};