class Solution {
public:
    
    bool possible(int capacity, vector<int>& weights, int days){

        int day = 1;
        int load = 0;

        for(int w : weights){

            if(load + w <= capacity){
                load += w;
            }
            else{
                day++;
                load = w;
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0 ;
        for(int x : weights){
            r+=x;
        }
        
        int ans ;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(possible(mid,weights,days)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};