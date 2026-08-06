class Solution {
public:

    vector<vector<int>> adj;
    vector<int> subtree;
    vector<int> ans;

    void dfs1 (int node  , int par  ,  int depth)
    {
        ans[0]+= depth;
        subtree[node]= 1;


        for(auto child : adj[node]){
            if(par == child)continue;


            dfs1(child , node , depth +1);

            subtree[node] +=subtree[child];
        }
    }

    void dfs2 (int node  , int par , int n )
    {
        for( auto child : adj[node]){
            if(child == par )continue;


            ans[child] = ans[node] + n - 2* subtree[child] ;

            dfs2(child , node , n);


        }

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        subtree.resize(n);
        ans.resize(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0, -1, 0);

        dfs2(0, -1, n);

        return ans;
    }
};