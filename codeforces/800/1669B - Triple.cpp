#include <bits/stdc++.h>
using namespace std;

int calculate(int n) {
    unordered_map<int, int> hm;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        hm[temp]++;
        if (hm[temp] == 3) {
            ans = temp;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        int n;
        cin >> n;

        int ans = calculate(n);
        cout << ans << endl;
    }
    
    return 0;
}
