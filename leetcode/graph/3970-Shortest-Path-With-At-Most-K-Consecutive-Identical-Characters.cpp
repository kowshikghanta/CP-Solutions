using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
#define pb push_back

class Solution {
public:
    ll INF = 1e18;
    vvi adj;
    vvll dist;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        adj.assign(n, vi());

        for (auto &e : edges) {
            adj[e[0]].pb(e[1]);
        }

        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].pb({e[1], e[2]});
        }

        dist.assign(n, vll(k + 1, INF));

        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [wt, u, cnt] = pq.top();
            pq.pop();

            if (wt != dist[u][cnt]) {
                continue;
            }

            if (u == n - 1) {
                return wt;
            }

            for (auto &[v, w] : graph[u]) {
                int temp = 1;

                if (labels[u] == labels[v]) {
                    temp = cnt + 1;
                }

                if (temp > k) {
                    continue;
                }

                if (wt + w < dist[v][temp]) {
                    dist[v][temp] = wt + w;
                    pq.push({wt + w, v, temp});
                }
            }
        }

        return -1;
    }
};