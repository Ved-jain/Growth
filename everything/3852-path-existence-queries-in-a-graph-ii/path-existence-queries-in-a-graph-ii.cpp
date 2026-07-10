class Solution {
public:
    vector<int>pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                             vector<vector<int>>& queries) {

        // {value, original index}
        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        // position of every original node in sorted array
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[a[i].second] = i;

        // next[i] = farthest index reachable in one edge
        vector<int> nxt(n);
        int j = 0;

        for(int i = 0; i < n; i++)
        {
            while(j + 1 < n && a[j + 1].first - a[i].first <= maxDiff)
                j++;

            nxt[i] = j;
        }

        // Binary lifting table
        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++)
        {
            for(int i = 0; i < n; i++)
            {
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto q : queries)
        {
            int l = pos[q[0]];
            int r = pos[q[1]];

            if(l > r)
                swap(l, r);

            // Different connected components
            if(a[r].first - a[l].first > maxDiff &&
               nxt[l] == l)
            {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int jump = 0;

            for(int k = LOG-1; k >= 0; k--)
            {
                if(up[k][cur] < r)
                {
                    cur = up[k][cur];
                    jump += (1<<k);
                }
            }

            if(cur < r)
            {
                if(nxt[cur] == cur)
                    ans.push_back(-1);
                else
                    ans.push_back(jump + 1);
            }
            else
            {
                ans.push_back(jump);
            }
        }

        return ans;
    }
};