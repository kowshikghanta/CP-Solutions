
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

class Solution {
public:
    ll MOD = 1e9 + 7;
    vvll dp;

    int numOfWays(vi& nums) {
        int n = nums.size();
        dp.assign(n + 1, vll(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return (recursion(nums) - 1 + MOD) % MOD;
    }

    ll recursion(vi& nums) {
        int n = nums.size();

        if (n <= 2) {
            return 1;
        }

        vi left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        ll l = recursion(left);
        ll r = recursion(right);

        ll ways = dp[n - 1][left.size()];
        ways = ways * l % MOD;
        ways = ways * r % MOD;

        return ways;
    }
};
