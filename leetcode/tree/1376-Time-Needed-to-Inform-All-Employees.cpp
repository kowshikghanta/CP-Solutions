class Solution {
public:
    std::vector<bool> visited;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        std::vector<vector<int>> graph(n);
        visited.assign(n, false);

        for (int i = 0; i < n; i++) {
            if (i != headID) {
                graph[manager[i]].push_back(i);
            }
        }

        return recursion(graph, informTime, headID);
    }

    int recursion(vector<vector<int>>& graph, vector<int>& informTime, int s) {
        visited[s] = true;

        int maximum = 0;

        for (int i : graph[s]) {
            if (!visited[i]) {
                maximum = std::max(maximum, recursion(graph, informTime, i));
            }
        }

        return informTime[s] + maximum;
    }
};