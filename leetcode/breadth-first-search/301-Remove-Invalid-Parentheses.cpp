class Solution {
public:
    int min;
    int n;
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        min = s.size();
        n = s.size();
        ans.clear();

        string cur = "";

        recursion(s, 0, 0, 0, cur);

        return ans;
    }

    void recursion(string& s, int idx, int count, int removed, string& cur) {
        if (count < 0 || removed > min) {
            return;
        }

        if (idx == n) {
            if (count == 0) {
                if (removed < min) {
                    min = removed;
                    ans.clear();
                    ans.push_back(cur);
                } else if (removed == min) {
                    if (find(ans.begin(), ans.end(), cur) == ans.end()) {
                        ans.push_back(cur);
                    }
                }
            }

            return;
        }

        if (s[idx] == '(' || s[idx] == ')') {
            recursion(s, idx + 1, count, removed + 1, cur);
        }

        cur += s[idx];

        recursion(
            s,
            idx + 1,
            count + (s[idx] == '(' ? 1 : (s[idx] == ')' ? -1 : 0)),
            removed,
            cur
        );

        cur.pop_back();
    }
};