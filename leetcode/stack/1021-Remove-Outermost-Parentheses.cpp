class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for (char c: s) {
            if (c == '(') {
                count++;
                if (count == 1) {
                    continue;
                }
            } else {
                count--;
                if (count == 0) {
                    continue;
                }
            }
            ans += c;
        }

        return ans;
    }
};