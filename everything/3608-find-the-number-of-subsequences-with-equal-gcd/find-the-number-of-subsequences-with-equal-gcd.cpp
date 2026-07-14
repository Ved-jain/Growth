class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int n;

    int solve(int i, int g1, int g2, vector<int>& nums) {
        if(i == n) return (g1 == g2 && g1 != 0);
    

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        ans += solve(i + 1, g1, g2, nums);

    
        ans += solve(i + 1, __gcd(g1, nums[i]), g2, nums);

       
        ans += solve(i + 1, g1, __gcd(g2, nums[i]), nums);

        return dp[i][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();

        int mx = 0;
        for (int x : nums)
            mx = max(mx, x);

        dp.assign(n + 1, vector<vector<int>>(mx + 1, vector<int>(mx + 1, -1)));

        return solve(0, 0, 0, nums);
    }
};