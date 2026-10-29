#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define f(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t-- != 0) {
        ll n;
        cin >> n;

        ll e = 0;
        ll o = 0;

        f(i, 0, n) {
            ll temp;
            cin >> temp;

            if (temp % 2) {
                o++;
            } else {
                e++;
            }
        }

        if ((o == 3 && e == 0) || (o == 1 && e == 1)) {
            cout << "Larpity\n";
        } else {
            cout << "Moggity\n";
        }
    }

    return 0;
}