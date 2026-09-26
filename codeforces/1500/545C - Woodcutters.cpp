#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        exit(0);
    }
    vector<vector<int>> a;

    for (int i = 0; i < n; i++) {
        int ai, h;
        cin >> ai >> h;
        a.push_back({ai, h});
    }


    sort(a.begin(), a.end(), [] (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
        
    int prev = a[0][0];
    int ans = 2;

    for (int i = 1; i < n - 1; i++) {
        if (prev < a[i][0] - a[i][1]) {
            ans++;
            prev = a[i][0];
        } else if (a[i][0] + a[i][1] < a[i + 1][0]) {
            ans++;
            prev = a[i][0] + a[i][1];
        } else {
            prev = a[i][0];
        }
    }

    cout << ans << endl;
    
    return 0;
}