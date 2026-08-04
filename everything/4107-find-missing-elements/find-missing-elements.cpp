class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        for(int x : nums){
            st.insert(x);

        }

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>ans;

        for(int i = mini ; i<=maxi ; i++){

            if(st.count(i)!=0){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans ;

    }
};