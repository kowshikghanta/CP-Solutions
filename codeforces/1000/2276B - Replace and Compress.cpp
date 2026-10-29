#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t-- != 0) {
        string s;
        cin >> s;

        ll ans = 1;

        if (s.find("010") != string::npos || s.find("101") != string::npos) {
            ans++;
        }

        if (s.find("000") != string::npos || s.find("111") != string::npos) {
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}