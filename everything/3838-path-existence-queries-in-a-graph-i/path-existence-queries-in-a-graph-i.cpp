class Solution {
public:
    vector<int>parent  , size ;

    int Uparent(int node){
        if(parent[node]==node)return node;

        return parent[node] = Uparent(parent[node]);
    }


   void Union(int u,int v)
    {
        int pu= Uparent(u);
        int pv= Uparent(v);

        if(pu==pv)
            return;

        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }

    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i< n; i++){
            parent[i]=i;
        }


        for(int i = 1 ; i< n; i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                Union(i , i-1 );
            }
        }
        vector<bool>ans;
        for(auto q : queries){
            int u = q[0];
            int v = q[1];

            if(Uparent(u)==Uparent(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};