class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;

    int solve(int l, int r, vector<int>& stones) {
        if(l>=r) return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int total = pref[r + 1] - pref[l];

        int left = total - stones[l] - solve(l + 1, r, stones);
        int right = total - stones[r] - solve(l, r - 1, stones);

        return dp[l][r] = max(left, right);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        dp.assign(n, vector<int>(n, -1));

        pref.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + stones[i];
        }
        return solve(0, n - 1, stones);
    }
};