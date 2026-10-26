
class Solution {
public:
    vector<int> parent;
    vector<long long> sum;

    int findup(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findup(parent[node]);
    }

    void unionBysum(int u, int v) {
        int uu = findup(u);
        int uv = findup(v);

        if (uu == uv)
            return;

        if (sum[uu] < sum[uv]) {
            parent[uu] = uv;
            sum[uv] += sum[uu];
        } else {
            parent[uv] = uu;
            sum[uu] += sum[uv];
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        parent.resize(total);
        iota(parent.begin(), parent.end(), 0);

        sum.assign(total, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i * n + j] = grid[i][j];
            }
        }

        int dr[] = {0, 1};
        int dc[] = {1, 0};

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                for (int d = 0; d < 2; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr < m && nc < n &&
                        grid[nr][nc] > 0) {
                        unionBysum(i * n + j, nr * n + nc);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < total; i++) {
            if (parent[i] == i &&
                sum[i] > 0 && sum[i] % k == 0) {
                ans++;
            }
        }

        return ans;
    }
};
