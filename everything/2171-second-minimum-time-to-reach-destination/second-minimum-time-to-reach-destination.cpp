class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>>adj(n+1);

        for(auto it : edges){

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> first(n+1 , 1e9) , second(n+1 , 1e9) ;

        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        first[1] = 0 ;

        pq.push({0 , 1 });

        while(!pq.empty()){
            auto [t , node] = pq.top();
            pq.pop();


            if((t/change)%2==1)
            {
                t = ((t/change)+1)* change ;
            }

            for(auto child : adj[node]){

                int newtime =  t + time ;

                if(newtime < first[child])
                {
                    second[child]= first[child];
                    first[child] = newtime;
                    pq.push({newtime , child});
                }

                else if(newtime>first[child] && newtime<second[child])
                {
                    second[child]= newtime;
                    pq.push({newtime , child});
                }
            }

        }
        return second[n];
    }
};