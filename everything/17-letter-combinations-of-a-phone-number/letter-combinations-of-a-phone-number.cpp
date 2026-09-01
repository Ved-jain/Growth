class Solution {
public:
    void solve(int i , vector<string>&mp , string temp , vector<string>&ans , string digits){
        if(i==digits.size()){
            ans.push_back(temp);
            return ;
        }

        for(char c : mp[digits[i]-'0']){
            temp.push_back(c);
            solve(i+1 , mp , temp , ans , digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        vector<string>ans;
        solve(0 , mp , temp , ans , digits);
        return ans ;
    }
};