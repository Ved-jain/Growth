class Solution {
public:
    vector<vector<vector<long long>>> dp;
    vector<int> req;
    int m;

    long long solve(int l, int r, int side) {

        if(l == 0 && r == m-1)
            return 0;

        if(dp[l][r][side] != -1)
            return dp[l][r][side];

        int cur;

        if(side == 0)
            cur = req[l];
        else
            cur = req[r];

        int left = m - (r-l+1);

        long long ans = 1e18;

        // Go to left
        if(l > 0) {
            int dist = abs(cur - req[l-1]);

            ans = min(ans,
                1LL * dist * left +
                solve(l-1, r, 0)
            );
        }

        // Go to right
        if(r+1 < m) {
            int dist = abs(cur - req[r+1]);

            ans = min(ans,
                1LL * dist * left +
                solve(l, r+1, 1)
            );
        }

        return dp[l][r][side] = ans;
    }

    long long elevatorRequests(
        int n,
        int start,
        vector<int>& requests
    ) {

        sort(requests.begin(), requests.end());

        // Remove start because it is fulfilled at time 0
        for(int x : requests) {
            if(x != start)
                req.push_back(x);
        }

        m = req.size();

        if(m == 0)
            return 0;

        dp.assign(
            m,
            vector<vector<long long>>(
                m,
                vector<long long>(2, -1)
            )
        );

        long long ans = 1e18;

        // Choose the first request
        for(int i = 0; i < m; i++) {

            int dist = abs(start - req[i]);

            ans = min(
                ans,
                1LL * dist * m + solve(i, i, 0)
            );
        }

        return ans;
    }
};