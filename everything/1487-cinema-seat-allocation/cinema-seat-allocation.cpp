class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int,int>rows;
        for(auto it : res ){
            int row = it[0];
            int seat = it[1];

            rows[row] |= (1<<seat);
        }

        int left = (1<<2) | (1<<3) | (1<<4) | (1<<5) ;

        int middle = (1<<4) | (1<<5) | (1<<6) | (1<<7) ;

        int right = (1<<6) | (1<<7) | (1<<8) | (1<<9) ;

        long long ans = 0 ;

        for(auto it : rows){

            int mask = it.second;

            if((mask & left) == 0 && (mask & right) == 0) ans += 2;

            else if((mask & left) == 0 || (mask & middle) == 0 || (mask & right) == 0) ans += 1;

        }

        ans += 2* (n- rows.size());
        return ans ;

    }
};