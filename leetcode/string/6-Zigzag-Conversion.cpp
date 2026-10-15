class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) {
            return s;
        }
        
        vector<string> rows(numRows, "");
        int cur = 0;
        bool reverse = false;

        for (int i = 0; i < n; i++) {
            rows[cur] += s[i];

            if (reverse) {
                cur--;
            } else {
                cur++;
            }
            if (cur == numRows) {
                cur = numRows - 2;
                reverse = true;
            } else if (cur == -1) {
                cur = 1;
                reverse = false;
            }
        }

        string ans = "";
        for (string s: rows) {
            ans += s;
        }

        return ans;
    }
};