class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int r, int c1, int c2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(r >= n)
            return 0;

        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherry = grid[r][c1];

        if(c1 != c2)
            cherry += grid[r][c2];

        int ans = 0;

        for(int d1 = -1; d1 <= 1; d1++) {
            for(int d2 = -1; d2 <= 1; d2++) {
                int nc1 = c1 + d1;
                int nc2 = c2 + d2;

                if(nc1 < 0 || nc1 >= m || nc2 < 0 || nc2 >= m)
                    continue;

                int next = solve(r + 1, nc1, nc2, grid);

                ans = max(ans, next);
            }
        }

        return dp[r][c1][c2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n , vector<vector<int>>(m , vector<int>(m,-1)));
        return solve(0 , 0 , m-1 , grid);
    }
};