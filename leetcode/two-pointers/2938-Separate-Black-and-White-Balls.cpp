class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0LL;
        long long cnt = 0LL;

        for (int i = n - 1; i > -1; i--) {
            if (s[i] == '0') {
                cnt++;
            } else {
                ans += cnt;
            }
        }

        return ans;
    }
};