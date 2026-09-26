#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        long long n;
        cin >> n;
        int ans = n;

        for (int i = 4; i <= n + 1; i *= 2) {
            if (n % (i - 1) == 0) {
                ans = n / (i - 1);
                break;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
