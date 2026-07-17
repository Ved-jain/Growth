class Solution {
public:
    int n , m;
    vector<vector<int>> dp;
    int solve(int i , int j,vector<vector<int>>& dungeon ){
        if(i>= m || j>=n)return 1e9;


        if(i == m - 1 && j == n - 1)
        {
            return max(1, 1 - dungeon[i][j]);
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int need = min(solve(i+1,j,dungeon),solve(i,j+1,dungeon));

        return dp[i][j]= max(1,need-dungeon[i][j]);
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, dungeon);
    }
};