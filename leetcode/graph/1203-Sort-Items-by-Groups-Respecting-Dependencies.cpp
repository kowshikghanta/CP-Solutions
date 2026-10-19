using vvi = vector<vector<int>>;
using vi = vector<int>;
#define f(x, y) for(int i = x; i < y; i++)
#define pb push_back

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vvi groups(m + n);
        unordered_map<int, vector<int>> hm;

        f(0, n) {
            if (group[i] == -1) {
                group[i] = m++;
            }
            hm[group[i]].pb(i);
        }

        vvi itemgraph(n), groupgraph(m);
        vi itemindegree(n, 0), groupindegree(m, 0);

        f(0, n) {
            for (int prev : beforeItems[i]) {
                itemgraph[prev].pb(i);
                itemindegree[i]++;

                if (group[prev] != group[i]) {
                    groupgraph[group[prev]].pb(group[i]);
                    groupindegree[group[i]]++;
                }
            }
        }

        queue<int> q;
        vi itemorder, grouporder;

        f(0, n) {
            if (itemindegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            itemorder.pb(u);

            for (int v : itemgraph[u]) {
                itemindegree[v]--;
                if (itemindegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (itemorder.size() != n) {
            return {};
        }

        f(0, m) {
            if (groupindegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            grouporder.pb(u);

            for (int v : groupgraph[u]) {
                groupindegree[v]--;
                if (groupindegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (grouporder.size() != m) {
            return {};
        }

        unordered_map<int, vi> sorteditems;

        for (int i : itemorder) {
            sorteditems[group[i]].pb(i);
        }

        vi ans;

        for (int g : grouporder) {
            for (int item : sorteditems[g]) {
                ans.pb(item);
            }
        }

        return ans;
    }
};