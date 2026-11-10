
class Solution {
public:
    vector<long long> dp;

    long long solve(int i, int n, vector<int>& costs) {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        long long ans = LLONG_MAX;

        for(int j = i + 1; j <= min(n, i + 3); j++) {
            long long cost = costs[j - 1] + (j - i) * (j - i);

            ans = min(ans, cost + solve(j, n, costs));
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n + 1, -1);

        return solve(0, n, costs);
    }
};
