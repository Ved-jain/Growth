class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , string& s , string& t ){
        if(j<0) return 1 ;
        if(i<0 && j>=0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];

        if(s[i]==t[j]){

            int tk = solve(i-1 , j-1 , s , t );
            int nt = solve(i-1 , j , s , t ) ; 

            return dp[i][j] =  tk + nt ;
        }
        return solve(i-1 , j , s , t);


        

            
    }
    int numDistinct(string s, string t) {

            int n = s.size();
            int m = t.size();
            dp.resize(n , vector<int>(m , -1 ));
           return  solve(n-1 , m-1 , s , t);
    }
};