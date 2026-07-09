class Solution {
public:
    
    bool possible(int divisor, vector<int>& nums, int threshold) {
        int sum = 0;

        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int ans = r;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (possible(mid, nums, threshold)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};