class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // flow of code - > 
        // first check that how many times a given query is illuminated or by how many bulbs then after processing that reduce the number by 1 
        // so we need to first mark all the bulbs first and store the nummber but its 1e9 n so what can be done 
        //    i need to store something in map to figure out that the given queury fits in that but how oto do that 

        // building part im doing first where im building the main light s

        unordered_map<int,int> row , col , diag1 , diag2 ;
        set<pair<int,int>>uni;
        vector<int>ans;
        for(auto x : lamps){
            int r = x[0];
            int c = x[1];

            if(uni.count({r,c}))continue;

            uni.insert({r,c});
            row[r]++;
            col[c]++;
            diag1[r+c]++;
            diag2[r-c]++;
        }
        vector<int> dx = {-1,-1,-1,0,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,0,1,-1,0,1};
        for(auto q : queries){
            int r = q[0];
            int c = q[1];


            if(row[r] || col[c]|| diag1[r+c] || diag2[r-c]){
                ans.push_back(1);
            }

            else{
                ans.push_back(0);
            }


            for(int k =0 ; k<8 ; k++){

                int nr = r + dx[k];
                int nc = c+ dy[k];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n)continue;

                if(uni.count({nr,nc})){

                    uni.erase({nr,nc});

                    row[nr]--;
                    col[nc]--;
                    diag1[nr+nc]--;
                    diag2[nr-nc]--;

                }

            }      
        }
        return ans ;

    }
};