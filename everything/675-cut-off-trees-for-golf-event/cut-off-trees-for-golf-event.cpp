class Solution {
public:

    int m, n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int bfs(int sr, int sc, int tr, int tc, vector<vector<int>>& forest){

        if(sr == tr && sc == tc)
            return 0;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({sr, sc});
        vis[sr][sc] = 1;

        int dist = 0;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                auto [x, y] = q.front();
                q.pop();

                if(x == tr && y == tc)
                    return dist;

                for(int k = 0; k < 4; k++){

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < m && ny>= 0 && ny < n && !vis[nx][ny] && forest[nx][ny]!= 0){

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }

            dist++;
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {

        m = forest.size();
        n = forest[0].size();

        vector<vector<int>> trees;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(forest[i][j] > 1){
                    trees.push_back({forest[i][j], i, j});
                }

            }
        }

        sort(trees.begin(), trees.end());

        int ans = 0;
        int r = 0, c = 0;

        for(auto &tree : trees){

            int nr = tree[1];
            int nc = tree[2];

            int d = bfs(r, c, nr, nc, forest);

            if(d == -1)
                return -1;

            ans += d;

            r = nr;
            c = nc;
        }

        return ans;
    }
};