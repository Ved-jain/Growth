class Solution {
public:

    long long minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        vector<pair<int,int>> points;

        
        points.push_back({start[0],start[1]});
        points.push_back({target[0],target[1]});

        for(auto &r : specialRoads){
            points.push_back({r[0],r[1]});
            points.push_back({r[2],r[3]});
        }

        map<pair<int,int>,int> mp;
        vector<pair<int,int>> nodes;

        for(auto p : points){
            if(mp.count(p)==0){
                mp[p]=nodes.size();
                nodes.push_back(p);
            }
        }

        int n = nodes.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;

                int x1 = nodes[i].first;
                int y1 = nodes[i].second;

                int x2 = nodes[j].first;
                int y2 = nodes[j].second;

                int cost = abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,cost});
            }
        }

        for(auto &r : specialRoads){

            int u = mp[{r[0],r[1]}];
            int v = mp[{r[2],r[3]}];

            adj[u].push_back({v,r[4]});
        }

    
        vector<long long> dist(n,LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        int src = mp[{start[0],start[1]}];
        int dest = mp[{target[0],target[1]}];

        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){

            auto [d,node]=pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto [child,cost]:adj[node]){

                if(dist[child]>d+cost){

                    dist[child]=d+cost;
                    pq.push({dist[child],child});
                }
            }
        }

        return dist[dest];
    }
};