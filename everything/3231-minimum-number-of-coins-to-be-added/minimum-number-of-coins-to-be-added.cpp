class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        long long reach = 0 ;
        int ans = 0 ;
        int i = 0;
        while(reach<target){
            if(i<n && coins[i]<=reach+1){
                reach+=coins[i];
                i++;
            }
            else{
                reach += reach +1;
                ans++;
            }
        }
        return ans;
    }
};