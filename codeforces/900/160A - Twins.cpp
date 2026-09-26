#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
        total += temp;
    }

    sort(a.begin(), a.end());

    int count = 0;
    int sum = 0;

    for (int i = n - 1; i > -1; i--) {
        if (sum > total - sum) {
            break;
        }

        count++;
        sum += a[i];
    }

    cout << count << endl;

    return 0;
}