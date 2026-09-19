class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();

        vector<int> first(26,-1),last(26,-1);

        for(int i=0;i<n;i++)
        {
            int x=s[i]-'a';

            if(first[x]==-1)
                first[x]=i;

            last[x]=i;
        }

        vector<pair<int,int>> intervals;

        for(int c=0;c<26;c++)
        {
            if(first[c]==-1)
                continue;

            int l=first[c];
            int r=last[c];

            bool valid=true;

            for(int j=l;j<=r;j++)
            {
                int x=s[j]-'a';

                if(first[x]<l)
                {
                    valid=false;
                    break;
                }

                r=max(r,last[x]);
            }

            if(valid)
                intervals.push_back({l,r});
        }

        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });

        vector<string> ans;
        int prev=-1;

        for(auto &p:intervals)
        {
            if(p.first>prev)
            {
                ans.push_back(s.substr(p.first,p.second-p.first+1));
                prev=p.second;
            }
        }

        return ans;
    }
};