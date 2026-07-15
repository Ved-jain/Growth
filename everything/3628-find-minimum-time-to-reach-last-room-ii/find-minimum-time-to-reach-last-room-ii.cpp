class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int m = moveTime.size();
        int n = moveTime[0].size();

        long long INF = 4e18;

        vector<vector<vector<long long>>> dist(
            m, vector<vector<long long>>(n, vector<long long>(2, INF))
        );

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        dist[0][0][0] = 0;

        // time, row, col, parity
        pq.push({0, 0, 0, 0});

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            long long time = cur[0];
            int row = cur[1];
            int col = cur[2];
            int parity = cur[3];

            if(time > dist[row][col][parity])
                continue;

            int cost = (parity == 0 ? 1 : 2);

            for(int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    long long newTime = max(time, (long long)moveTime[nr][nc]) + cost;
                    int newParity = parity ^ 1;

                    if(newTime < dist[nr][nc][newParity])
                    {
                        dist[nr][nc][newParity] = newTime;
                        pq.push({newTime, nr, nc, newParity});
                    }
                }
            }
        }

        return (int)min(dist[m-1][n-1][0], dist[m-1][n-1][1]);
    }
};