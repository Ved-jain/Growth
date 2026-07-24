class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
       unordered_set<int> pair;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                pair.insert(nums[i]^nums[j]);
        }

        unordered_set<int> ans;

        for(int x:nums)
        {
            for(int y:pair)
            ans.insert(x^y);
        }

        return ans.size();
        
    }
};