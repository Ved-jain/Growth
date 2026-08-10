class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int , vector<int>>mp;

        for(int i = 0 ; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        vis[0]=1;
        int steps;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int i = q.front();
                q.pop();

                if(i==n-1){
                    return steps;
                }
                // for the front index

                if(i+1< n && !vis[i+1]){
                    vis[i+1] = 1 ;
                    q.push(i+1);
                }
                
                if(i-1>= 0 && !vis[i-1]){
                    vis[i-1]=1;
                    q.push(i-1);
                }

                for(auto x : mp[arr[i]]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }
                }

                mp[arr[i]].clear();
            }
            steps++;
        }
        return steps;
        
    }
};