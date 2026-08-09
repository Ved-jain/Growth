class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int M, vector<int>& piles, vector<int>& pref) {
        int n = piles.size();

        if(i >= n) return 0;

        if(dp[i][M] != -1) return dp[i][M];

        int ans = 0;

        for(int x = 1; x <= 2*M && i+x <= n; x++) {
            int rem = pref[n] - pref[i];

            int opp = solve(i+x, max(M,x), piles, pref);

            int take = rem - opp;

            ans = max(ans, take);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        dp.resize(n, vector<int>(n+1, -1));

        vector<int> pref(n+1, 0);

        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + piles[i];
        }

        return solve(0, 1, piles, pref);
    }
};