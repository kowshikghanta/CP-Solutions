class Solution {
public:
    bool checkGoodInteger(int n) {
        vector<int> a = sod(n);
        return a[1] - a[0] >= 50;
    }
    vector<int> sod(int n) {
        vector<int> ans(2, 0);

        while (n != 0) {
            ans[0] += (n % 10);
            ans[1] += (n % 10) * (n % 10);
            n /= 10;
        }

        return ans;
    }
};