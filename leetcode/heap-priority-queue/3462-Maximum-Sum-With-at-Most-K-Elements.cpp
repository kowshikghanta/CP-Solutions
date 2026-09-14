class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int m = grid.size();
        int n = grid[0].size();
        std::priority_queue<int> pq;
        long long ans = 0;

        for (vector<int>& a: grid) {
            std::sort(a.begin(), a.end(), [] (int a, int b) {
                return b < a;
            });
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < limits[i]; j++) {
                pq.push(grid[i][j]);
            }
        }

        for (int i = 0; i < k; i++) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};