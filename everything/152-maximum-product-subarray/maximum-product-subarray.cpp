class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        vector<int> mx(n), mn(n);

        mx[n-1] = nums[n-1];
        mn[n-1] = nums[n-1];

        int ans = nums[n-1];

        for(int i = n-2; i >= 0; i--){

            int a = nums[i];
            int b = nums[i] * mx[i+1];
            int c = nums[i] * mn[i+1];

            mx[i] = max({a,b,c});
            mn[i] = min({a,b,c});

            ans = max(ans, mx[i]);
        }

        return ans;
    }
};