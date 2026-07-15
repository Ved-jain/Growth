class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int,int>>q;
        set<pair<int,int>>vis;
        
        q.push({0,0});
        vis.insert({0,0});

        while(!q.empty()){
            auto[a,b] = q.front();
            q.pop();
            if(a+b == target) return true;
            vector<pair<int,int>>nxt;

            nxt.push_back({0,b});          // empty X
            nxt.push_back({a,0});          // empty Y
            nxt.push_back({x,b});          // fill X
            nxt.push_back({a,y});          // fill Y

            int t=min(a,y-b);
            nxt.push_back({a-t,b+t});      // X -> Y

            t=min(b,x-a);
            nxt.push_back({a+t,b-t});      // Y -> X

            for(auto it: nxt){
                if(!vis.count(it)){

                    vis.insert(it);
                    q.push(it);
                }
            }

        }
        return false;
    }
};