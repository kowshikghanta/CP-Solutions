class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> hm;
        hm[')'] = '(';
        hm[']'] = '[';
        hm['}'] = '{';
        

        for (char c: s) {
            if (c == ')' || c == ']' || c == '}') {
                if (st.empty() || st.top() != hm[c]) {
                    return false;
                }
                st.pop();
                continue;
            }
            st.push(c);
        }

        return st.empty();
    }
};