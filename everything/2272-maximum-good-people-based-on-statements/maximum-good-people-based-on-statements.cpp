class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0 ;


        for(int mask = 0 ; mask<(1<<n) ; mask++){
            bool ok = true;
            for(int i = 0 ;  i<n && ok ; i++){

                if(mask & (1<<i)){
                
                    for(int j = 0 ; j<n ; j++){

                        if(statements[i][j] == 2) continue;

                        // i says that j is good 
                        if(statements[i][j]==1){
                            // if i already said that j is bad so now making j good dosent make sense so break
                            if(!(mask & (1<<j))){
                                ok = false;
                                break;
                            } 
                        }
                        else 
                        {
                            if((mask & (1<<j))){
                                ok = false;
                                break;
                            } 


                        }
                        
                       
                    }
                }



            }

            if(ok){
                ans = max(ans ,  __builtin_popcount(mask));
            }


        }
        return ans;
        

    }
};