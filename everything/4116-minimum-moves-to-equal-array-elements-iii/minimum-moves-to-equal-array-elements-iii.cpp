class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin() , nums.end());
        int ans = 0 ; 
        for(auto zx : nums){
            ans+= mx - zx ; 

        }
        return ans ;
    }
};