using vvs = vector<vector<string>>;
using vs = vector<string>;
#define pb push_back

class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();

        string ms1 = "";
        string ms2 = "";

        vvs ans;

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i] && ms1 != "") {
                vs temp;
                temp.pb(ms1);
                temp.pb(ms2);
                ans.pb(temp);
                ms1 = "";
                ms2 = "";
            } else if (s1[i] != s2[i]) {
                ms1 += s1[i];
                ms2 += s2[i];
            }
        }

        if (ms1 != "") {
            vs temp;
            temp.pb(ms1);
            temp.pb(ms2);
            ans.pb(temp);
        }

        return ans;
    }
};