class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin() , folder.end());
        vector<string>ans;
        string par ; 

        for(int i = 0 ; i < n ; i++)
        {   
            if(ans.empty()){
                ans.push_back(folder[i]);
                continue;
            }

            string par = ans.back();

            if(folder[i].substr(0 , par.size())== par && folder[i][par.size()]=='/'){
                continue;
            }
            ans.push_back(folder[i]);
        }
        return ans;
    }
};