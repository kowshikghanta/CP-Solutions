class Solution {
public:
    int n;

    int scheduleCourse(vector<vector<int>>& courses) {
        n = courses.size();

        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += courses[i][0];
            pq.push(courses[i][0]);

            if (sum > courses[i][1]) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};