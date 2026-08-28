class Solution {
public:

    bool dfs(int x, int y, int tx, int ty, unordered_set<long long>& blocked, unordered_set<long long>& visited,int limit) {

        long long code = 1LL * x * 1000000 + y;

        if(x < 0 || x >= 1000000 || y < 0 || y >= 1000000)
            return false;

        if(blocked.count(code))
            return false;

        if(visited.count(code))
            return false;

        visited.insert(code);

        if(x == tx && y == ty)
            return true;

        if(visited.size() > limit)
            return true;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i=0;i<4;i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(dfs(nx,ny,tx,ty,blocked,visited,limit))
                return true;
        }

        return false;
    }


    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        int b = blocked.size();

    
        int limit = b * (b - 1) / 2;

        unordered_set<long long> blockedSet;

        for(auto &v : blocked){

            long long code = 1LL * v[0] * 1000000 + v[1];

            blockedSet.insert(code);
        }

        unordered_set<long long> visited1;

        if(!dfs(source[0],source[1],target[0],target[1], blockedSet,visited1,limit))
            return false;


        unordered_set<long long> visited2;

        if(!dfs(target[0],target[1],source[0],source[1], blockedSet,visited2,limit))
            return false;

        return true;
    }
};