#define vi vector<int>
#define vvi vector<vector<int>>
using ll = long long;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<vi, vvi, greater<vi>> availableHeap;
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> unavailableHeap;

        for (int i = 0; i < n; i++) {
            availableHeap.push({servers[i], i});
        }

        vector<int> ans;
        ll time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            while (!unavailableHeap.empty() && unavailableHeap.top()[0] <= time) {
                vector<ll> cur = unavailableHeap.top();
                unavailableHeap.pop();

                availableHeap.push({(int)cur[1], (int)cur[2]});
            }

            if (availableHeap.empty()) {
                time = unavailableHeap.top()[0];

                while (!unavailableHeap.empty() && unavailableHeap.top()[0] <= time) {
                    vector<ll> cur = unavailableHeap.top();
                    unavailableHeap.pop();

                    availableHeap.push({(int)cur[1], (int)cur[2]});
                }
            }

            vi cur = availableHeap.top();
            availableHeap.pop();

            ans.push_back(cur[1]);

            unavailableHeap.push({time + tasks[i], cur[0], cur[1]});
        }

        return ans;
    }
};