class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        deque<vector<int>> dq;

        dist[0][0] = 0;
        dq.push_front({0,0});

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        while(!dq.empty())
        {
            auto cur = dq.front();
            dq.pop_front();

            int r = cur[0];
            int c = cur[1];

            int cost = dist[r][c];

            for(int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int wt = 1;

                    if(grid[r][c] == k + 1)
                        wt = 0;

                    if(cost + wt < dist[nr][nc])
                    {
                        dist[nr][nc] = cost + wt;

                        if(wt == 0)
                            dq.push_front({nr,nc});
                        else
                            dq.push_back({nr,nc});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};