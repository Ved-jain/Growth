class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefmax(n) , sufmin(n);
        prefmax[0]=nums[0];
        sufmin[n-1]= nums[n-1];
        for(int i = 1 ; i<n;i++){
            prefmax[i] = max(nums[i], prefmax[i-1]);
            

        }
        for(int i = n-2 ; i>=0 ; i--){
            sufmin[i] = min(nums[i], sufmin[i+1]);
        }
        vector<int>ans(n);
        ans[n-1] = prefmax[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            if(prefmax[i]>sufmin[i+1]){
                ans[i] = ans[i+1];
            }
            else{
                ans[i] = prefmax[i];
            }
        }
        return ans ;
    }
};