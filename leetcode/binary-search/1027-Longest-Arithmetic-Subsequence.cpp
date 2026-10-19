using vi = vector<int>;
using ll = long long;
using vvll = vector<unordered_map<int, int>>;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vvll dp(n);
        int ans = 0;

        for (int idx = 0; idx < n; idx++) {
            for (int previdx = 0; previdx < idx; previdx++) {
                int difference = nums[idx] - nums[previdx];

                int take = 2;

                if (dp[previdx].count(difference)) {
                    take = dp[previdx][difference] + 1;
                }

                dp[idx][difference] = take;
                ans = max(ans, take);
            }
        }

        return ans;
    }
};