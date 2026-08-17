class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;

    int sum(int l, int r){
        return pref[r + 1] - pref[l];
    }

    int solve(int l, int r, vector<int>& st){
        if(l == r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for(int mid = l; mid < r; mid++){
            int left = sum(l, mid);
            int right = sum(mid + 1, r);

            if(left < right){
                ans = max(ans, left + solve(l, mid, st));
            }

            else if(right < left){
                ans = max(ans, right + solve(mid + 1, r, st));
            }

            else{
                ans = max(ans, left + max(solve(l, mid, st), solve(mid + 1, r, st)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& st) {
        int n = st.size();

        dp.assign(n, vector<int>(n, -1));

        pref.resize(n + 1, 0);

        for (int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + st[i];
        }

        return solve(0, n - 1, st);
    }
};