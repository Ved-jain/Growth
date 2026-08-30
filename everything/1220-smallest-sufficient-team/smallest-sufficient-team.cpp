class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req,vector<vector<string>>& peo) {
        int m = req.size();
        int n = peo.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            mp[req[i]] = i;
        }

        vector<int> pmask(n, 0);

        for (int i = 0; i < n; i++) {

            for (auto skill : peo[i]) {
                pmask[i] |= (1 << mp[skill]);
            }
        }
        int total = 1<<m;
        int full = total - 1;

        vector<int> dp(total, 1e9);
        vector<vector<int>>team(total);
        dp[0]=0;

        for(int i = 0 ; i<n;i++)
        {
            for(int mask = 0 ; mask<total ; mask++){
                if(dp[mask]==1e9)continue;


                int newmask = mask|pmask[i];
                if(dp[newmask]>dp[mask]+1){
                    dp[newmask] = dp[mask]+1;
                    team[newmask]=team[mask];

                    team[newmask].push_back(i);
                }
            }
        }
        return team[full];
    }
};