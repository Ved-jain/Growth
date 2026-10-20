class Solution {
public:
    bool sortable(vector<int>&a){
        int n = a.size();
        int change = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(a[i]> a[(i+1)%n] )change++;
        }
        return change<=1 ;
    }

    bool correct(vector<int>& nums, int k) {
        int n = nums.size();
        int prevmax = INT_MIN;

        for (int start = 0; start < n; start += k) {
            vector<int> a;

            for (int j = start; j < start + k; j++) {
                a.push_back(nums[j]);
            }

            
            if (!sortable(a))
                return false;

            int mn = *min_element(a.begin(), a.end());
            int mx = *max_element(a.begin(), a.end());

            
            if (prevmax > mn)
                return false;

            prevmax = mx;
        }

        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        // 1st step find the divisors 
        // 2nd step find the subarrays of k size 
        // 3rd step check if the subarrays is cyclic sortable 
        // 4th step max of prev array < min of curr array adj obv 
        // if yes then add that to the answer 
        // use helper function for better code
        int n = nums.size(); 
        int ans = 0 ;
        for(int i = 1 ; i*i<=n ; i++){
            if(n%i==0){
                if(correct(nums , i)){
                    ans+= i;
                }
                if(i!= n/i){
                    if(correct(nums , n/i)){
                        ans+= n/i;
                    }
                }
            }
        }
        return ans ;
    }
};