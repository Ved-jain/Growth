class Solution {
public:

    int dr[4] = {1, -1, 0 , 0 };
    int dc[4] = {0,0,1,-1};

   bool check(int wait, vector<vector<int>>& grid, vector<vector<int>>& firetime)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<vector<int>> q;

    if(wait >= firetime[0][0])
    {
        return false;
    }

    q.push({wait, 0, 0});
    vis[0][0] = true;

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        int time = it[0];
        int r = it[1];
        int c = it[2];

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(grid[nr][nc] == 2)
                continue;

            if(vis[nr][nc])
                continue;

            int newtime = time + 1;

            if(nr == m-1 && nc == n-1)
            {
                if(newtime <= firetime[nr][nc])
                {
                    return true;
                }
            }
            else
            {
                if(newtime < firetime[nr][nc])
                {
                    vis[nr][nc] = true;
                    q.push({newtime, nr, nc});
                }
            }
        }
    }

    return false;
}
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();    

        vector<vector<int>>firetime(m , vector<int>(n , INT_MAX));

        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    firetime[i][j]=0;
                    q.push({i,j});
                }
            }
        }
       
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            for(int k = 0 ; k<4;k++){
                int nr = r+ dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<m && nc <n&& grid[nr][nc]!=2){
                    
                    if(firetime[r][c]+1 < firetime[nr][nc]){
                        firetime[nr][nc] = firetime[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }

        }


        int lo = 0 ;
        int hi = 1e9;
        int ans = -1 ;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2 ;

            if(check(mid,grid,firetime)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans ;

    }
};