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

        long long ans = pow(2, n - k + 1);

        cout << ans + (2 * (k - 1)) << endl;;
    }
    
    return 0;
}
