class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // time, lastMoveCost, row, col
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;

        // previous move = 2 so first move becomes 1
        pq.push({0,2,0,0});

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int lastMove = cur[1];
            int row = cur[2];
            int col = cur[3];

            if(time > dist[row][col])
                continue;

            if(row == m-1 && col == n-1)
                return time;

            int cost;

            if(lastMove == 1)
                cost = 2;
            else
                cost = 1;

            for(int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int newTime = max(time, moveTime[nr][nc]) + cost;

                    if(newTime < dist[nr][nc])
                    {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, cost, nr, nc});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};