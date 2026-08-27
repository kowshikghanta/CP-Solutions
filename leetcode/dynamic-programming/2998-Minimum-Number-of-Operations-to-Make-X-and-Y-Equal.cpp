class Solution {
public:
    int MAX = 100001;
    vector<int> dp;
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        dp = vector<int>(x + 1, -1);
        return recursion(x, y);
    }

    int recursion(int x, int y) {
        if (x <= y) {
            return y - x;
        }
        if (dp[x] != -1) {
            return dp[x];
        }
        //nearest 11 greater
        int a = (11 - x % 11) % 11;
        a = a + 1 + recursion((a + x) / 11, y);

        //nearest 11 less
        int b = x % 11;
        b = b + 1 + recursion((x - b) / 11, y);

        //nearest 5 greater
        int c = (5 - x % 5) % 5;
        c = c + 1 + recursion((c + x) / 5, y);

        //nearest 5 less
        int d = x % 5;
        d = d + 1 + recursion((x - d) / 5, y);

        int decrement = 1 + recursion(x - 1, y);

        return dp[x] = std::min({a, b, c, d, decrement});
    }
};