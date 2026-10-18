
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        int root = nums[0];

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftways = solve(left);
        long long rightways = solve(right);

        int L = left.size();
        int R = right.size();

        long long ways = C[L + R][L];

        ways = ways * leftways % MOD;
        ways = ways * rightways % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        C.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] = (
                    C[i - 1][j - 1] +
                    C[i - 1][j]
                ) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
