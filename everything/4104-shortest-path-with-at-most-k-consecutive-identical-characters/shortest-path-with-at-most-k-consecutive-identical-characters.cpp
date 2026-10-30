class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<vector<int>>dist(n , vector<int>(k+1 , 1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        //cpst node and streaks
        
        pq.push({0 , 0 , 1});
        dist[0][1]= 0 ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cost = it[0];
            int node = it[1];
            int streak = it[2];

            if(cost> dist[node][streak])continue;

            for(auto  it : adj[node]){
                int nei = it.first;
                int wt = it.second;

                int next ;

                if(labels[nei]==labels[node]){
                    next = streak + 1;
                }
                else{
                    next =1;
                }
                if(next>k)continue;

                if(cost + wt < dist[nei][next]){
                    dist[nei][next] = cost+wt;


                    pq.push({dist[nei][next],nei , next});
                }


                
            }



            
        }
        int ans = 1e9;
        for(int i = 1 ; i<=k ; i++){
            ans = min(ans , dist[n-1][i]);
        }
        if(ans==1e9)return -1;
        else{
              return ans;    
              }
    }
};