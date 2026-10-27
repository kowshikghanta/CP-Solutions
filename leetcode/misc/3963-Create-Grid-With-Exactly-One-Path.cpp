class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        int i = 0, j = 0;
        

        while (i < m) {
            ans[i++][0] = '.';
        }

        while (j < n) {
            ans[m - 1][j++] = '.';
        }
        
        return ans;
    }
};
