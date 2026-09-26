class Solution {
public:
    vector<int> dp;
    int MOD = 1000000007;
    int countHousePlacements(int n) {
        dp.assign(n, -1);
        int p = recursion(0, n);
        long long ans = 1LL * p * p;

        return ans % MOD ;
    }

    int recursion(int cur, int n) {
        if (cur >= n) {
            return 1;
        }
        if (dp[cur] != -1) {
            return dp[cur];
        }
        int place = recursion(cur + 2, n);
        int dontplace = recursion(cur + 1, n);

        return dp[cur] = (place + dontplace) % MOD;
    }
};