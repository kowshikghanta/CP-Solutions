class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;

        for (int i: nums) {
            if (i % 6 == 0) {
                ans += i;
                cnt++;
            }
        }

        return cnt == 0 ? 0 : ans / cnt;
    }
};