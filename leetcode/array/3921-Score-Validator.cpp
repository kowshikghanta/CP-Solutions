class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        std::vector<int> ans(2, 0);

        for (string s: events) {
            if (s == "W") {
                ans[1]++;
            } else if (s == "WD") {
                ans[0]++;
            } else if (s == "NB") {
                ans[0]++;
            } else {
                ans[0] += s[0] - '0';
            }

            if (ans[1] == 10) {
                break;
            }
        }

        return ans;
    }
};