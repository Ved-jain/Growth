class Solution {
public:
   bool possible(int limit, int k, vector<int>& nums){

    int curr = 0;
    int parti = 1;

    for(int x : nums){

        if(curr + x <= limit){
            curr += x;
        }
        else{
            parti++;
            curr = x;
        }
    }

    return parti <= k;
}
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = 0 ;
        for(int x:nums){
            hi+=x;
        }
        int ans ;

        while(lo<=hi){
           int  mid = lo + (hi-lo)/2 ;

            if(possible(mid,k,nums)){
                ans = mid;
                hi = mid-1;
            }
            else{lo = mid+1;}
        }
        return ans;
    }
};