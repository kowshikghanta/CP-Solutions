using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define pb push_back

class Solution {
public:
    int LOG;
    vvi adj, up;
    vi tin, tout, depth, bit;
    string s;
    int timer = 0;

    void update(int idx, int val, int n) {
        while (idx <= n) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans ^= bit[idx];
            idx -= idx & -idx;
        }

        return ans;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    void rangeUpdate(int u, int val, int n) {
        update(tin[u], val, n);
        update(tout[u] + 1, val, n);
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->s = s;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, vi());
        up.assign(n, vi(LOG, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].pb(e[1]);
            adj[e[1]].pb(e[0]);
        }

        dfs(0, 0);

        for (int i = 0; i < n; i++) {
            rangeUpdate(i, 1 << (s[i] - 'a'), n);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string op;
            int u, v;

            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int val = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                rangeUpdate(u, val, n);
                s[u] = c;
            }
            else {
                ss >> v;

                int w = lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ (1 << (s[w] - 'a'));

                ans.pb((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};