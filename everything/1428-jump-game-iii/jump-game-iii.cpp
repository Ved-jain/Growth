class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){

            if(i + arr[i] < n){
                adj[i].push_back(i + arr[i]);
            }

            if(i - arr[i] >= 0){
                adj[i].push_back(i - arr[i]);
            }
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            if(arr[node] == 0)
                return true;

            for(auto child : adj[node]){

                if(!vis[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }

        return false;
    }
};