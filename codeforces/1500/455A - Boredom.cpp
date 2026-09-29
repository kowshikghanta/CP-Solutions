#include <bits/stdc++.h>
using namespace std;

long long recursion(long long idx, vector<long long>& frequency, vector<long long>& dp, long long n) {
    if (idx > n) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    long long pick = frequency[idx] * idx + recursion(idx + 2, frequency, dp, n);
    long long nopick = recursion(idx + 1, frequency, dp, n);

    return dp[idx] = max(pick, nopick);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long maximum = 0;
    vector<long long> nums;

    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        nums.push_back(temp);
        maximum = max(temp, maximum);
    }

    vector<long long> frequency(maximum + 1, 0);

    for (long long i : nums) {
        frequency[i]++;
    }

    vector<long long> dp(maximum + 1, -1);

    long long ans = recursion(1, frequency, dp, maximum);

    cout << ans;

    return 0;
}