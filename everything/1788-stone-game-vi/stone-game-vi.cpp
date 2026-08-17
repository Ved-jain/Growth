class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();

        priority_queue<pair<int,int>>pq;

        for(int i = 0; i < n; i++){
            pq.push({a[i] + b[i], i});
        }

        int alice = 0, bob = 0;

        for(int i = 0; i < n; i++) {
            int idx = pq.top().second;
            pq.pop();

            if(i % 2 == 0) alice += a[idx];
            else bob += b[idx];
        }

        if(alice > bob) return 1;
        if(alice < bob) return -1;
        return 0;
    }
};