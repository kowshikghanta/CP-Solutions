#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, n;
        cin >> x >> n;

        long long mod = n % 4;
        long long ans;

        if (mod == 0) {
            ans = x;
        }
        else if (mod == 1) {
            if (x % 2 == 0)
                ans = x - n;
            else
                ans = x + n;
        }
        else if (mod == 2) {
            if (x % 2 == 0)
                ans = x + 1;
            else
                ans = x - 1;
        }
        else {
            if (x % 2 == 0)
                ans = x + n + 1;
            else
                ans = x - n - 1;
        }

        cout << ans << '\n';
    }

    return 0;
}