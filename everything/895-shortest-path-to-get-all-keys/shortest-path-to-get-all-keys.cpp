class Solution {
public:

    struct node{
        int row;
        int col;
        int mask;
        int dist;
    };

    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int k = 0;
        int sr = 0;
        int sc = 0;

        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == '@'){
                    sr = i;
                    sc = j;
                }

                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    k = max(k, grid[i][j] - 'a' + 1);
                }
            }
        }

        
        vector<vector<vector<int>>>vis(
            m,
            vector<vector<int>>(n, vector<int>(1<<k, 0))
        );

        queue<node>q;

        
        q.push({sr, sc, 0, 0});
        vis[sr][sc][0] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int finalMask = (1<<k) - 1;

        while(!q.empty()){

            node curr = q.front();
            q.pop();

            int row = curr.row;
            int col = curr.col;
            int mask = curr.mask;
            int dist = curr.dist;

            // We have collected every key
            if(mask == finalMask){
                return dist;
            }

            // Try 4 directions
            for(int d = 0; d < 4; d++){

                int nr = row + dr[d];
                int nc = col + dc[d];

                // Outside grid
                if(nr < 0 || nr >= m || nc < 0 || nc >= n){
                    continue;
                }

                // Wall
                if(grid[nr][nc] == '#'){
                    continue;
                }

                int newMask = mask;

                // If it is a lock
                if(grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F'){

                    int key = grid[nr][nc] - 'A';

                    // Don't have corresponding key
                    if((mask & (1<<key)) == 0){
                        continue;
                    }
                }

                // If it is a key
                if(grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f'){

                    int key = grid[nr][nc] - 'a';

                    newMask = mask | (1<<key);
                }

                // This exact state has already been visited
                if(vis[nr][nc][newMask]){
                    continue;
                }

                vis[nr][nc][newMask] = 1;

                q.push({nr, nc, newMask, dist + 1});
            }
        }

        return -1;
    }
};