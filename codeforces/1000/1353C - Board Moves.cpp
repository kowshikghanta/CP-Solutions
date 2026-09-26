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
        n *= n;
        n -= 1;

        long long count = 1;
        long long off = 8;

        long long ans = 0;

        while (n != 0) {
            ans += (count * off);
            n -= off;
            off += 8;
            count += 1;
        }

        cout << ans << endl;
    }
    
    return 0;
}
