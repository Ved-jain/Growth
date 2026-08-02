class Solution {
public:

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    bool solve(int r, int c, int idx, vector<vector<char>>& board, string &word, vector<vector<bool>>& vis)
    {
        if(idx == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;

        if(vis[r][c])
            return false;

        if(board[r][c] != word[idx])
            return false;

        vis[r][c] = true;

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(solve(nr, nc, idx + 1, board, word, vis))
                return true;
        }

        vis[r][c] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j< n; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(i, j, 0, board, word, vis))
                        return true;
                }
            }
        }

        return false;
    }
};