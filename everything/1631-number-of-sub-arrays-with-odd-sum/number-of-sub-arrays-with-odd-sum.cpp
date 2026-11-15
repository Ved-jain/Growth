class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long mod=1e9+7;
        long long even=1,odd=0,ans=0;
        long long sum=0;

        for(int x:arr){
            sum+=x;

            if(sum%2==0){
                ans=(ans+odd)%mod;
                even++;
            }
            else{
                ans=(ans+even)%mod;
                odd++;
            }
        }

        return ans;
    }
};