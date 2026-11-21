#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll x;
        cin >> x;

        ll ans = x;

        f(i, 0, x + 1) {
            ll power = i + 1;
            ll damage = 0;
            ll moves = i;

            while (damage < x) {
                damage += power;
                moves++;

                if (power > 1) {
                    power--;
                }
            }

            ans = min(ans, moves);
        }

        cout << ans << '\n';
    }

    return 0;
}