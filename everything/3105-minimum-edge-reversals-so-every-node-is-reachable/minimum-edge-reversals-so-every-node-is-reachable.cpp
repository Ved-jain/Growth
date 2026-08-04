class Solution {
public:

    void dfs(int node,int par, vector<int>&ans,
             vector<vector<pair<int,int>>>&adj){

        for(auto it : adj[node]){

            int child = it.first;
            int cost = it.second;

            if(child==par)
                continue;

            ans[0] += cost;

            dfs(child,node,ans,adj);
        }
    }

    void dfs2(int node,int par, vector<int>&ans,
              vector<vector<pair<int,int>>>&adj){

        for(auto it : adj[node]){

            int child = it.first;
            int cost = it.second;

            if(child==par)
                continue;

            if(cost==0)
                ans[child] = ans[node] + 1;
            else
                ans[child] = ans[node] - 1;

            dfs2(child,node,ans,adj);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        vector<int> ans(n,0);

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : edges){

            int u = it[0];
            int v = it[1];

            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        dfs(0,-1,ans,adj);

        dfs2(0,-1,ans,adj);

        return ans;
    }
};