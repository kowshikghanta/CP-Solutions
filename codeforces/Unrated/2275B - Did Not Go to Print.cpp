
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- != 0) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> st;
        vector<bool> printed(n + 1, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                st.push_back(i + 1);
            } else if (s[i] == '2') {
                if (!st.empty()) {
                    printed[st.back()] = true;
                    st.pop_back();
                } else {
                    printed[i + 1] = true;
                }
            } else {
                printed[i + 1] = true;
            }
        }

        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (!printed[i]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';

        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}
