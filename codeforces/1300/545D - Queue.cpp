#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> nums;

    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    sort(nums.begin(), nums.end());

    long long sum = 0;
    int ans = 0;

    for (int i: nums) {
        if (sum <= i) {
            ans += 1;
            sum += i;
        }
    }

    cout << ans;
    
    return 0;
}
