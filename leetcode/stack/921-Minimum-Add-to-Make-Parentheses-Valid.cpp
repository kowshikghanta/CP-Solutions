class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        
        for (char c: s) {
            if (c == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    ans += 1;
                } else {
                    st.pop();
                }
            }
        }

        return ans + st.size();
    }
};