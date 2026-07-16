class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> temp = nums;

        bool one = true;
        bool minus1 = true;

        int ops = 0;

        for(int i = 0; i < n - 1; i++){
            if(temp[i] != 1){
                temp[i] = 1;
                temp[i + 1] *= -1;
                ops++;
            }
        }

        if(temp[n - 1] != 1 || ops > k)
            one = false;

        ops = 0;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] != -1){
                nums[i] = -1;
                nums[i + 1] *= -1;
                ops++;
            }
        }

        if(nums[n - 1] != -1 || ops > k)
            minus1 = false;

        return one || minus1;
    }
};