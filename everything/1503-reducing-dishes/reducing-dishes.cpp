class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int time  , vector<int>& sat){
        int n = sat.size();
        if(i>=n)return 0 ;
        if(dp[i][time]!= -1)return dp[i][time];


        int take = (sat[i] * time) + solve(i+1 , time+1 , sat);
        int skip = solve(i+1  , time , sat);

        return dp[i][time] = max(take , skip);

    }
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        dp.assign(n , vector<int>(n+1 , - 1));
        sort(sat.begin() , sat.end());
        return solve( 0 , 1 , sat);
    }
};

