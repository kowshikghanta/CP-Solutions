#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

    while (t--) {
        ll m, n;
        cin >> m >> n;

        string a, b;
        cin >> a >> b;

        unordered_map<char, int> hm;

        for (char c : a) hm[c]++;

        bool flag = true;

        for (char c : b) {
            hm[c]--;
            if (hm[c] < 0) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            cout << "NO\n";
            continue;
        }

        for (const auto& [key, value] : hm) {
            if (!(key == 's' || key == 'i' || key == 'x') && value != 0) {
                flag = false;
                break;
            }
        }

        if (hm['s'] == 1 && hm['i'] == 1 && hm['x'] == 1) {
            cout << (flag ? "YES\n" : "NO\n");
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}