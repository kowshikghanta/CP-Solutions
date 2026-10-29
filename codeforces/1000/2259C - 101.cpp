#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vi vector<int>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t-- != 0) {
        string s;
        
        vi a;
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.pb(temp);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                break;
            }
            if (a[i] == -1) {
                a[i] = 1;
                break;
            }
        }

        for (int i = n - 1; i > -1; i--) {
            if (a[i] == 1) {
                break;
            }
            if (a[i] == -1) {
                a[i] = 1;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = 0;
            }
        }

        for (int i: a) {
            cout << i << " ";
        }

        cout << endl;
    }
    
    return 0;
}

