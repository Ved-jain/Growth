class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>adj(n*n +1) ;
        vector<int>value(n*n +1 );
        int count = 1;
        // creating a simple node struct
        for(int i = n-1 ; i>=0 ; i--){
            
            if((n-i-1 )%2==0){

                for(int j = 0 ; j<n ; j++)
                {
                    value[count] = board[i][j];
                    count++;
                }

            }

            else{

                for(int j = n-1 ; j>=0 ; j--)
                {
                    value[count] = board[i][j];
                    count++;
                }
            }
        }

        //adj list banara hu 

        for(int cur = 1 ; cur<=n*n ;cur++){

            for(int k = 1; k<=6 ; k++){
                int next = cur + k;

                if(next>n*n)break;

                if(value[next]!=-1) next=value[next];

                adj[cur].push_back(next);
            }
        }

        vector<int>dist(n*n+1 ,-1);
        queue<int>q;
        dist[1]=0 ;
        q.push(1);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == n*n) return dist[node] ;

            for(auto it : adj[node]){
                if(dist[it]!=-1){
                    continue;
                }

                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
        return -1;
    }
};