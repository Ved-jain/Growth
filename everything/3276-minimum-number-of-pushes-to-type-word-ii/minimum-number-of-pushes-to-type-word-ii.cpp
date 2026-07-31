class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int>freq(26);
        for(char c : word){
            freq[c - 'a']++;
        }
        int ans = 0 ;
        sort(freq.rbegin(),freq.rend());
        for(int i = 0 ; i< 26; i++){
            ans += (freq[i] * (i/8 +1 )) ;
        }
        return ans ;
    }
};