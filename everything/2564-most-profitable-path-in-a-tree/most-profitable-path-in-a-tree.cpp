class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> bobTime;
    int ans = INT_MIN;

    void dfsParent(int node, int par) {
        parent[node] = par;

        for (int child : adj[node]) {
            if (child == par) continue;
            dfsParent(child, node);
        }
    }

    void dfsAlice(int node, int par, int time, int income, vector<int>& amount) {

        if (time < bobTime[node]) {
            income += amount[node];
        }
        else if (time == bobTime[node]) {
            income += amount[node] / 2;
        }

        bool leaf = true;

        for (int child : adj[node]) {
            if (child == par) continue;
            leaf = false;
            dfsAlice(child, node, time + 1, income, amount);
        }

        if (leaf) {
            ans = max(ans, income);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n = amount.size();

        adj.resize(n);
        parent.resize(n);
        bobTime.assign(n, 1e9);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsParent(0, -1);

        int t = 0;
        int cur = bob;

        while (cur != -1) {
            bobTime[cur] = t;
            cur = parent[cur];
            t++;
        }

        dfsAlice(0, -1, 0, 0, amount);

        return ans;
    }
};