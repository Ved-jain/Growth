class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0 ;
        vector<int>pref(n);
        for(int i = 0 ; i<n;i++){
            maxi = max(maxi , nums[i]);
            pref[i] = __gcd(nums[i],maxi);
        }

        sort(pref.begin(),pref.end());
        long long ans = 0 ;
        int i = 0 ;
        int j = n-1;
        while(i<j){
            ans+= __gcd(pref[i],pref[j]);
            i++;
            j--;
        }
        return ans;

    }
};