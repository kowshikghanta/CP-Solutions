using ll = long long;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int v = nums[i];

            dp[v + 1] = max(dp[v + 1], dp[v] + 1);
            dp[v] = max(dp[v], dp[v - 1] + 1);

            ans = max({ans, dp[v], dp[v + 1]});
        }

        return ans;
    }
};