class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> ans(2, 0);
        std::unordered_set<int> hs;

        for (vector<int>& i: grid) {
            for (int j: i) {
                if (hs.contains(j)) {
                    ans[0] = j;
                }
                hs.insert(j);
            }
        }

        for (int i = 1; i <= n * n; i++) {
            if(!hs.contains(i)) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};