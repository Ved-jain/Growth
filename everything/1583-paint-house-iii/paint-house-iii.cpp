class Solution {
public:
    int m, n, target;
    int INF = 1e9;

    vector<vector<vector<int>>> dp;

    int solve(int i, int neigh, int prevColor,
              vector<int>& houses, vector<vector<int>>& cost) {

        if(neigh > target)
            return INF;

        if(i == m) {
            if(neigh == target)
                return 0;

            return INF;
        }

        if(dp[i][neigh][prevColor] != -1)
            return dp[i][neigh][prevColor];

        int ans = INF;

        
        if(houses[i] != 0) {

            int color = houses[i];

            int newNeigh = neigh;

            if(color != prevColor)
                newNeigh++;

            ans = solve(i+1, newNeigh, color, houses, cost);
        }

      
        else {

            for(int color = 1; color <= n; color++) {

                int newNeigh = neigh;

                if(color != prevColor)
                    newNeigh++;

                int curr = cost[i][color-1];

                int next = solve(i+1, newNeigh, color,
                                 houses, cost);

                if(next != INF)
                    ans = min(ans, curr + next);
            }
        }

        return dp[i][neigh][prevColor] = ans;
    }

    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int m, int n, int target) {

        this->m = m;
        this->n = n;
        this->target = target;

        dp.assign(m,
                  vector<vector<int>>(
                      target + 1,
                      vector<int>(n + 1, -1)
                  ));

        int ans = solve(0, 0, 0, houses, cost);

        if(ans == INF)
            return -1;

        return ans;
    }
};