class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zor = 0;
        int n = nums.size();
        int zero = 0;

        for(auto z : nums) {
            zor ^= z;

            if(z == 0)
                zero++;
        }

        if(zor)
            return n;
        else {
            if(zero == n)
                return 0;
            else
                return n-1;
        }
    }
};