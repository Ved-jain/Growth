
class Solution {
public:
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> par, depth, tin, tout, sz, pref;
    string s;
    vector<int> bit;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void add(int i, int val) {
        while (i <= n + 1) {
            bit[i] ^= val;
            i += i & -i;
        }
    }

    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res ^= bit[i];
            i -= i & -i;
        }
        return res;
    }

    void rangeXor(int l, int r, int val) {
        add(l + 1, val);
        add(r + 2, val);
    }

    int getPref(int u) {
        return pref[u] ^ sum(tin[u] + 1);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (d & (1 << j))
                u = up[j][u];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return par[u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        par.assign(n, 0);
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        sz.assign(n, 1);
        pref.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Build DFS order and root-prefix masks iteratively.
        vector<int> order;
        vector<int> st = {0};
        par[0] = 0;
        pref[0] = mask(s[0]);

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == par[u]) continue;

                par[v] = u;
                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ mask(s[v]);
                up[0][v] = u;
                st.push_back(v);
            }
        }

        // Calculate subtree sizes and subtree intervals.
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (u != 0)
                sz[par[u]] += sz[u];
        }

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        // Build binary lifting table.
        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            string x;

            stringstream ss(q);
            ss >> type >> u >> x;

            if (type == "update") {
                char c = x[0];

                int delta = mask(s[u]) ^ mask(c);

                rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v = stoi(x);
                int w = lca(u, v);

                int pathMask = getPref(u) ^ getPref(v) ^ mask(s[w]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
