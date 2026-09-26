#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, n;
    cin >> s;
    cin >> n;
    vector<vector<int>> a;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        int ds, y;
        cin >> ds >> y;
        temp.push_back(ds);
        temp.push_back(y);
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), [] (const vector<int>& p, const vector<int>& q) {
        return p[0] < q[0];
    });

    for (int i = 0; i < n; i++) {
        if (a[i][0] >= s) {
            flag = false;
            break;
        }
        s += a[i][1];
    }

    cout << (flag ? "YES" : "NO");
    
    return 0;
}
