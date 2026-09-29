class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, int rem, vector<vector<char>>& grid){

        if(rem < 0)
            return false;

        if(rem > m + n)
            return false;

        if(i == m-1 && j == n-1){
            return rem == 0;
        }

        if(dp[i][j][rem] != -1)
            return dp[i][j][rem];

        bool down = false;
        bool right = false;

        
        if(i < m-1){

            int nr = rem;

            if(grid[i+1][j] == '(')
                nr++;
            else
                nr--;

            down = solve(i+1, j, nr, grid);
        }

      
        if(j < n-1){

            int nr = rem;

            if(grid[i][j+1] == '(') nr++;
            else  nr--;

            right = solve(i, j+1, nr, grid);
        }

        return dp[i][j][rem] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        
        dp.assign(m,vector<vector<int>>(n, vector<int>(m+n+1, -1)));

        int rem = 0;

        
        if(grid[0][0] == '(')
            rem++;
        else
            rem--;

        return solve(0, 0, rem, grid);
    }
};