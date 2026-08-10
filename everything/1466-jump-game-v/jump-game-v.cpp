class Solution {
public:
    vector<int>dp;

    int solve(int i , int d , vector<int>&arr){
        int n = arr.size();
        if(i<0 || i>=n) return 0;


        if(dp[i]!=-1) return dp[i] ;
        int ans = 1 ;

        // right 
        for(int x = 1  ;  x<= d && x + i < n ; x++){
            if(arr[x+i]>=arr[i])break;

            ans = max(ans , 1  + solve(x+i  , d , arr));
        }

        // left side 

        for(int x = 1 ; x<=d  && i-x >= 0 ; x++){
            if(arr[i-x] >= arr[i])break;

            ans = max(ans , 1+ solve(i-x , d , arr )); 
        }

        return dp[i]= ans  ;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.assign(n+1 , -1);
        int ans = 1 ;
         
        for(int i = 0 ; i<n ; i++){
            ans = max( ans , solve(i , d , arr));
        }
        return ans ;
    }
};