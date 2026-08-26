class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        string ans = "";

        for(int right = 0; right < s.size(); right++) {

            if(s[right] == '1')
                count++;

            if(count == k) {

                
                while(s[left] == '0')
                    left++;

                int len = right - left + 1;
                string cur = s.substr(left, len);

                
                if(len < minLen) {
                    minLen = len;
                    ans = cur;
                }

               
                else if(len == minLen && cur < ans) {
                    ans = cur;
                }

               
                left++;
                count--;
            }
        }

        return ans;
    }
};