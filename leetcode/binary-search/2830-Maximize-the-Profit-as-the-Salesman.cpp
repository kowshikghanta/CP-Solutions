class Solution {
public:
    int n;
    vector<int> dp;
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        n = offers.size();
        dp.assign(n, -1);
        std::sort(
            offers.begin(),
            offers.end(),
            [] (const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        return recursion(offers, n, 0);
    }
    
    int recursion(vector<vector<int>>& offers, int n, int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int skip = recursion(offers, n, i + 1);

        int next = std::lower_bound(
            offers.begin() + i + 1,
            offers.end(),
            offers[i][1],
            [] (const vector<int>& offer, int end) {
                return offer[0] <= end;
            }
        ) - offers.begin();

        int take = offers[i][2] + recursion(offers, n, next);

        dp[i] = std::max(skip, take);

        return dp[i];
    }
};