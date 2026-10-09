class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    ans++;
                } else {
                    st.pop();
                }
                if (i == n - 1 || s[i + 1] != ')') {
                    ans++;
                } else {
                    i++;
                }
            }
        }

        return ans + 2 * st.size();

    }
};