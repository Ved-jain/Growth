class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        sort(sources.begin(), sources.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });

        queue<vector<int>> q;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(auto x : sources) {
            int r = x[0];
            int c = x[1];
            int colour = x[2];

            ans[r][c] = colour;
            q.push({r, c, colour});
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it[0];
            int c = it[1];
            int colour = it[2];

            for(int k = 0; k < 4; k++) {

                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if(ans[nr][nc] != 0)
                    continue;

                ans[nr][nc] = colour;

                q.push({nr, nc, colour});
            }
        }

        return ans;
    }
};