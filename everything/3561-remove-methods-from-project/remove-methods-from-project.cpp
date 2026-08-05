class Solution {
public:
    vector<int> vis;

    void dfs(int node, vector<vector<int>>& adj)
    {
        vis[node] = 1;

        for(auto child : adj[node])
        {
            if(!vis[child])
                dfs(child, adj);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        vis.assign(n, 0);

        for(auto x : invocations)
        {
            adj[x[0]].push_back(x[1]);
        }

       
        dfs(k, adj);

       
        for(auto x : invocations)
        {
            int u = x[0];
            int v = x[1];

            if(!vis[u] && vis[v])
            {
                vector<int> ans;
                for(int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

      
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};