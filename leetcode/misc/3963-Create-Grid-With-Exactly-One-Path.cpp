class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        int i = 0, j = 0;
        while (i < m && j < n) {
            ans[i][j] = '.';
            if (i == j) {
                i++;
            } else {
                j++;
            }
        }

        while (i < m) {
            ans[i++][n - 1] = '.';
        }

        while (j < n) {
            ans[m - 1][j++] = '.';
        }
        return ans;
    }
};
