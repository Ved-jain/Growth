class Solution {
public:
    vector<vector<int>> dp;
    int limit;

    int solve(int i, int x, vector<int>& nums) {
        if (i == nums.size()) {
            return (x == 0) ? 0 : -1;
        }

        if (dp[i][x] != -2)
            return dp[i][x];

        // Not pick 
        int notPick = solve(i + 1, x, nums);

        // Pick 
        int pick = solve(i + 1, x ^ nums[i], nums);

        if (pick != -1)
            pick++;

        return dp[i][x] = max(pick, notPick);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        int mx = target;
        for (int num : nums)
            mx = max(mx, num);

        int bits = 1;
        while ((1LL << bits) <= mx)
            bits++;

        limit = 1 << bits;

        dp.assign(n, vector<int>(limit, -2));

        int kept = solve(0, target, nums);

        return (kept == -1) ? -1 : n - kept;
    }
};