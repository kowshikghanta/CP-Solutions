class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> hm;

        for (const vector<string>& v: knowledge) {
            hm[v[0]] = v[1];
        }

        string temp = "";
        string ans = "";
        bool insidebracket = false;

        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && !insidebracket) {
                ans += s[i];
                continue;
            }
            if (s[i] == '(') {
                insidebracket = true;
                continue;
            }
            if (s[i] == ')') {
                if (hm.contains(temp)) {
                    ans += hm[temp];
                } else {
                    ans += "?";
                }
                temp = "";
                insidebracket = false;
                continue;
            }
            temp += s[i];
        }

        return ans;
    }
};