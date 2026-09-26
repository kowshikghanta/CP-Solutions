#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        vector<int> b;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.push_back(temp);
            sum += temp;
        }

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            b.push_back(temp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0;
        int j = n - 1;

        for (int l = 0; l < k; l++) {
            if (a[i] >= b[j]) {
                break;
            }
            sum -= a[i];
            sum += b[j];
            i++;
            j--;
        }

        cout << sum << endl;
    }
    
    return 0;
}
