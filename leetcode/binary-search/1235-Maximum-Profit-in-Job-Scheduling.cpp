class Solution {
public:
    std::vector<int> dp;
    int n;
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        dp.assign(n, -1);
        vector<vector<int>> jobs(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        std::sort(jobs.begin(), jobs.end(), [] (const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        return recursion(jobs, 0);
    }

    int recursion(vector<vector<int>>& jobs, int i) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int skip = recursion(jobs, i + 1);

        int next = std::lower_bound(
            jobs.begin() + i + 1,
            jobs.end(),
            jobs[i][1],
            [] (const vector<int>& job, int endTime) {
                return job[0] < endTime;
            }
        ) - jobs.begin();

        int take = jobs[i][2] + recursion(jobs, next);

        dp[i] = std::max(take, skip);
        return dp[i];
    }
};