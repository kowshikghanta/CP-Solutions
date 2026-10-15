#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        long long a, b;
        cin >> a >> b;

        if (a <= b) {
            cout << -1 << endl;
            continue;
        }
        
        long long count = 0;

        while (a > b && b > 0 && a > 0) {
            count++;
            a -= 2;
            b -= 1;
        }

        cout << count << endl;
    }
    
    return 0;
}
