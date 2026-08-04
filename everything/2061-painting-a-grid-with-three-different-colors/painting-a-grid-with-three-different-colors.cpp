class Solution {
public:
    int mod = 1e9 + 7;

    vector<vector<int>> states;
    vector<vector<int>> adj;
    vector<vector<int>> dp;

    void generate(int row , int m , vector<int>&curr)
    {
        if(row == m){
            states.push_back(curr);
            return;
        }


        for(int i = 0 ; i <3 ; i++){
            if(row>0 && curr[row-1]==i)continue;
            curr.push_back(i);
            generate(row+1 , m , curr);
            curr.pop_back();
        }

    }

    bool works(vector<int>&a , vector<int>b){

        for(int i = 0 ; i<a.size(); i++){
            if(a[i]==b[i])return false;


        }
        return true;
    }


    int solve(int col , int prev , int n ){
        if(col==n){
            return 1 ;

        }

        if(dp[col][prev]!=-1){
            return dp[col][prev];

        }
        long long ans = 0 ;

        for(int nextState : adj[prev]){

            ans += solve(col + 1, nextState, n);
            ans %= mod;
        }
        return dp[col][prev] = ans;

    }

    int colorTheGrid(int m, int n) {
        
        vector<int>curr ;
        generate(0 , m , curr);

        int total = states.size();
        adj.resize(total);

        for(int i = 0; i < total; i++){

            for(int j = 0; j < total; j++){

                if(works(states[i], states[j])){

                    adj[i].push_back(j);
                }
            }
        }

        dp.assign(n, vector<int>(total, -1));

        long long ans = 0;

        for(int i = 0; i < total; i++){

            ans += solve(1, i, n);
            ans %= mod;
        }

        return ans;
    }
};