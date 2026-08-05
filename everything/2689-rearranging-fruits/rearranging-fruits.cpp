class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        

        map<int,int>cnt1 , cnt2 , total;
        int mn = INT_MAX;


        for(int x : basket1){
            cnt1[x]++;
            total[x]++;
            mn=min(mn , x);

        }
        for(int x : basket2){
            cnt2[x]++;
            total[x]++;
            mn=min(mn , x);
        }

        vector<int>ex1 , ex2 ;

        for(auto it : total){
            int val = it.first;
            int freq = it.second;

            if(freq%2)return -1;


            int need = freq/2;

            while(cnt1[val] > need){
                ex1.push_back(val);
                cnt1[val]--;
            }

            while(cnt2[val] > need){
                ex2.push_back(val);
                cnt2[val]--;
            } 


                
        }

        sort(ex1.begin(), ex1.end());
        sort(ex2.rbegin(), ex2.rend());
        long long ans = 0;

        for(int i = 0 ; i<ex1.size();i++){
           ans += min(1LL * min(ex1[i], ex2[i]), 2LL * mn);

        }
        return ans;   
    }
};