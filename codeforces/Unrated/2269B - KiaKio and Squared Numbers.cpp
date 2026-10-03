#include <bits/stdc++.h>
using namespace std;

int sod (long long a) {
    int sum = 0;

    while (a != 0) {
        sum += (a % 10) * (a % 10);
        a /= 10;
    }

    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        long long n;
        cin >> n;
        vector<long long> a;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            a.push_back(temp);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1000; j++) {
                a[i] = sod(a[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) {
                    ans++;
                }
            }
        }

        cout << ans << endl;

    }
    
    return 0;
}
