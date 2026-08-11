class Solution {
public:
    vector<vector<long long>>dp;
    long long mod = 1e9 + 7 ;
    long long solve(int i , int k )
    {
        if(i==0 ){
            if(k==0)return 1 ;

            return 0 ;


        }

        if(k<=0 || k>i)return 0 ;

        if(dp[i][k]!=-1) return dp[i][k]; 
        

        return dp[i][k] = (solve(i-1 , k-1 )  + (i-1)* solve(i-1 , k ))%mod;




    }
    int rearrangeSticks(int n, int k) {
        dp.assign(n+1 , vector<long long >(k+1 , -1));
        return solve(n , k );
    }
};