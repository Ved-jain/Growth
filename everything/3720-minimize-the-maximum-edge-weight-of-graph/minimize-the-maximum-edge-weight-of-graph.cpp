class Solution {
public:

    vector<int> vis;

    void dfs(int node, int weight, vector<vector<pair<int,int>>>& adj){

        vis[node] = 1;

        for(auto it : adj[node]){

            int v = it.first;
            int wt = it.second;

            if(wt > weight)
                continue;

            if(!vis[v])
                dfs(v, weight, adj);
        }
    }

    bool check(int weight, int n, vector<vector<pair<int,int>>>& adj){

        vis.assign(n, 0);

        dfs(0, weight, adj);

        for(int i = 0; i < n; i++){

            if(!vis[i])
                return false;
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<pair<int,int>>> adj(n);

        int lo = 0;
        int hi = 0;
        int ans = -1;

        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            hi = max(hi, wt);

            
            adj[v].push_back({u, wt});
        }

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(check(mid, n, adj)){

                ans = mid;
                hi = mid -1;
            }
            else{

                lo = mid + 1;
            }
        }

        return ans;
    }
};