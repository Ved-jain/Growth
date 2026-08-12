class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0 ; 
        int l = 0 ;
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int r = 0 ; r < n ; r++){
            freq[nums[r]]++;

            while(freq[nums[r]]>k ){
                freq[nums[l]]--;
                l++;
                if(freq[nums[l]]==0){
                    freq.clear();
                }
            }
            ans = max( ans ,  r - l +1);
        }
        return ans ;
    }
};