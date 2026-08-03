class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n + 3, 0);

        for(int i = n - 1; i >= 0; i--){

            int take1 = stoneValue[i] - dp[i + 1];

            int take2 = INT_MIN;
            if(i + 1 < n){
                take2 = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            }

            int take3 = INT_MIN;
            if(i + 2 < n){
                take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];
            }

            dp[i] = max({take1, take2, take3});
        }

        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};