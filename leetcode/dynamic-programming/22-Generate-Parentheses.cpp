class Solution {
public:
    vector<string> ans;
    int x;

    vector<string> generateParenthesis(int n) {
        ans.clear();
        x = n;
        string s = "";
        recursion(n, s, 0, 0);
        return ans;
    }

    void recursion(int n, string& s, int sum, int open) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }

        if (sum > 0) {
            s += ")";
            recursion(n - 1, s, sum - 1, open);
            s.pop_back();
        }

        if (open < x) {
            s += "(";
            recursion(n, s, sum + 1, open + 1);
            s.pop_back();
        }
    }
};