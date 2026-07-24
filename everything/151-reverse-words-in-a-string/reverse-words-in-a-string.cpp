class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";

        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    st.push(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }

        if (!temp.empty()) {
            st.push(temp);
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();

            if (!st.empty())
                ans += " ";
        }

        return ans;
    }
};