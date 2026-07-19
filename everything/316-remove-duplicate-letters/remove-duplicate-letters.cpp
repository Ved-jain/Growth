class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int> last(26);
        for(int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<int> vis(26, 0);
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(vis[ch - 'a'])
                continue;

            while(!st.empty() &&
                  st.top() > ch &&
                  last[st.top() - 'a'] > i) {

                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(ch);
            vis[ch - 'a'] = 1;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};