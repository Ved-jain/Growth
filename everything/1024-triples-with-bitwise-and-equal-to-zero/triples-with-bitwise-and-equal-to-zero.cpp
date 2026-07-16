class Solution {
public:
    int countTriplets(vector<int>& nums) {

        const int MAX = 1 << 16;

        vector<int> cnt(MAX, 0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                cnt[nums[i] & nums[j]]++;
            }
        }

        int ans = 0;

        for(int k = 0; k < nums.size(); k++){
            for(int mask = 0; mask < MAX; mask++){
                if((mask & nums[k]) == 0){
                    ans += cnt[mask];
                }
            }
        }

        return ans;
    }
};