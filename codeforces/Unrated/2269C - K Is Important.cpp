#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;

        if (2 * k <= n) {
            for (int i = k - 1; i <= n - k; i++) {
                ans += a[i];
            }

            int l = 0;
            int r = n - 1;

            for (int i = 0; i < k - 1; i++) {
                ans += max(a[l], a[r]);
                l++;
                r--;
            }
        } else {
            int pairs = n - k + 1;

            int l = 0;
            int r = n - 1;

            for (int i = 0; i < pairs; i++) {
                ans += max(a[l], a[r]);
                l++;
                r--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}