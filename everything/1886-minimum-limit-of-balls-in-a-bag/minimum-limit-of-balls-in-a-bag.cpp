class Solution {
public:
    int n;

    bool possible(int val, int maxOperations, vector<int>& nums){
        long long  moves = 0;

        for(int i = 0; i < n; i++){
            moves += (nums[i] - 1) / val;
        }

        return moves <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {

        n = nums.size();

        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        int ans = hi;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(possible(mid, maxOperations, nums)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};