class Solution {
public:
    int maxDepth(string t) {
        stack<char>s;
        int ans = 0 ;

        for(char c : t){
            if(c=='('){
                s.push(c);
            }
            else if(c==')'){
                s.pop();
            }
            ans=max(ans , (int)s.size());
        }
        return ans;
    }
};