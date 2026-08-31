class Solution {
public:
    bool check(string s , int l , int r ){
        if(l==r)return true;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int i , string s , vector<string>&temp , vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j = i ; j<s.size() ; j++){

            if(check(s , i , j)){
                temp.push_back(s.substr(i,j-i+1));

                solve(j+1 , s , temp , ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        solve(0 , s , temp , ans);
        return ans ;
    }
};