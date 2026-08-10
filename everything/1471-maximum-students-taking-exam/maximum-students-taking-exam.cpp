class Solution {
public:
    
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        
        vector<vector<int>> adj(m) ; 
        for(int r = 0 ; r<m ; r++){
            int broken = 0 ; 

            for(int c = 0 ; c<n ; c++){

                if(seats[r][c]=='#'){
                    broken |= (1<<c) ; 
                }
            }
        
            for(int mask = 0 ; mask < (1<<n) ; mask++){

                if(mask & (mask<<1))continue;

                if(mask & broken )continue;


                adj[r].push_back(mask) ; 

            }
        }


        vector<vector<int>>dp(m , vector<int>(1<<n , 0));

        for(auto mask   : adj[0]){
            dp[0][mask] = __builtin_popcount(mask);
        }


        for(int r = 1 ; r<m ; r++){

            for(auto curr : adj[r]){

                for(auto prev : adj[r-1]){
                    
                    if(curr & (prev<<1))continue;

                    if(curr & (prev>>1))continue;

                    dp[r][curr] = max( dp[r][curr] , dp[r-1][prev] + __builtin_popcount(curr));
                }
            }
        }

        int ans = 0;

        for(auto mask : adj[m-1]) {
            ans = max(ans, dp[m-1][mask]);
        }

        return ans;







    }
};