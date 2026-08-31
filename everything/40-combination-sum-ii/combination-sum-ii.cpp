class Solution {
public:
    void solve(int i,vector<int>&nums,int target,vector<int>&temp,
               int sum,vector<vector<int>>&ans){

        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(sum>target || i==nums.size())
            return;

        for(int j=i;j<nums.size();j++){

           
            if(j>i && nums[j]==nums[j-1])
                continue;

            if(sum+nums[j]>target)
                break;

            
            temp.push_back(nums[j]);

            solve(j+1,nums,target,temp,sum+nums[j],ans);

            
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>&nums,int target){

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        vector<int>temp;

        solve(0,nums,target,temp,0,ans);

        return ans;
    }
};