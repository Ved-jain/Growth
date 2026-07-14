class Solution {
public:
    vector<vector<int>> dp;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    int solve(int r, int c, vector<vector<int>>& matrix)
    {
        if(dp[r][c] != -1)
            return dp[r][c];

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 1;

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               matrix[nr][nc] > matrix[r][c])
            {
                ans = max(ans, 1 + solve(nr, nc, matrix));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        dp.resize(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};