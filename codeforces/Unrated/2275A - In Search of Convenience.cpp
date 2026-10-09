#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        long long x, y, R;
        cin >> x >> y >> R;
        cout << x - R << "\t" << y << endl;
    }
    
    return 0;
}
