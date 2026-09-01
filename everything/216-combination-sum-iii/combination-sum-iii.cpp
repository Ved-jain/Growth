class Solution {
public:

    void solve(int i, int k, int n, vector<int>&temp, vector<vector<int>>&ans, int sum){

        if(temp.size()==k){
            if(sum==n){
                ans.push_back(temp);
            }
            return;
        }

        for(int j=i; j<=9; j++){

            if(sum+j>n) break;

            temp.push_back(j);

            solve(j+1, k, n, temp, ans, sum+j);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>temp;
        vector<vector<int>>ans;

        solve(1, k, n, temp, ans, 0);

        return ans;
    }
};