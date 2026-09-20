class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int temp = s[i] - 'a' - 26;
            
            ans += (-temp * (i + 1));
        }

        return ans;
    }
};