class Solution {
public:

    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(int i, int k, vector<int>& nums){

        if(k==1)
            return suffix[i];

        if(dp[i][k]!=-1)
            return dp[i][k];

        int ans=INT_MAX;
        int sum=0;

        for(int j=i;j<=n-k;j++){

            sum+=nums[j];

            ans=min(ans,max(sum,solve(j+1,k-1,nums)));
        }

        return dp[i][k]=ans;
    }

    int splitArray(vector<int>& nums, int k) {

        n=nums.size();

        suffix.resize(n+1,0);

        for(int i=n-1;i>=0;i--)
            suffix[i]=suffix[i+1]+nums[i];

        dp.assign(n,vector<int>(k+1,-1));

        return solve(0,k,nums);
    }
};