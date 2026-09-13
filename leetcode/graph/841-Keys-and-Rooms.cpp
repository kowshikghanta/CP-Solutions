class Solution {
public:
    std::vector<bool> visited;
    int total = 0;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.assign(n, false);

        recursion(rooms, n, 0);

        return total == n;
    }

    void recursion(vector<vector<int>>& rooms, int n, int idx) {
        visited[idx] = true;
        total++;

        for (int i: rooms[idx]) {
            if (!visited[i]) {
                recursion(rooms, n, i);
            }
        }
    } 
};