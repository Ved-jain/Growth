class Solution {
public:
    vector<int>ans;
    void dfs(int num , int digits , int n , int k ){
        if(digits==n){
            ans.push_back(num);
            return;
        }

        int last = num%10;
        if(last+k<=9){
            dfs(num*10+last+k , digits+1 , n , k);
        }

        if(k!=0 && last-k>=0){
            dfs(num*10+ last-k , digits+1 ,n,k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i<=9 ; i++){
            dfs(i , 1 , n,k);
        }
        return ans;
    }
};