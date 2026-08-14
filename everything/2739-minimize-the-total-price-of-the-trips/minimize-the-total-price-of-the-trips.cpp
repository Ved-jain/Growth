class Solution {
public:
    int demand[100];
    vector<int> adj[100];

    int isInPath(int u, int dest, int p = -1) {

        if(u == dest) {
            demand[u]++;
            return 1;
        }

        for(auto v : adj[u]) {

            if(v == p)
                continue;

            if(isInPath(v, dest, u)) {
                demand[u]++;
                return 1;
            }
        }

        return 0;
    }

    pair<int,int> solve(int u, int p, vector<int>& price) {

        // first  -> u is halved
        // second -> u is not halved

        int take = (price[u] / 2) * demand[u];

        int dontTake = price[u] * demand[u];

        for(auto v : adj[u]) {

            if(v == p)
                continue;

            pair<int,int> child = solve(v, u, price);

            // u is NOT halved:
            // child can either be halved or not
            dontTake += min(child.first, child.second);

            // u IS halved:
            // child cannot be halved
            take += child.second;
        }

        return {take, dontTake};
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges,
                          vector<int>& price,
                          vector<vector<int>>& trips) {

        memset(demand, 0, sizeof(demand));

        for(int i = 0; i < n; i++)
            adj[i].clear();

        // Build tree
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Calculate how many times every node is used
        for(auto trip : trips) {

            int start = trip[0];
            int end = trip[1];

            isInPath(start, end);
        }

        // Tree DP
        pair<int,int> ans = solve(0, -1, price);

        // Root can either be halved or not
        return min(ans.first, ans.second);
    }
};