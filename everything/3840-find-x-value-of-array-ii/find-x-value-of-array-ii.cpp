class Solution {
public:
    static const int K=6;

    int n,k;
    vector<array<int,K>> tree;

    void makeLeaf(int node,int val)
    {
        tree[node].fill(0);

        int rem=val%k;

        tree[node][rem]=1;
        tree[node][k]=rem;
    }

    array<int,K> merge(array<int,K>&a,array<int,K>&b)
    {
        array<int,K> ans;
        ans.fill(0);

        int left=a[k];
        int right=b[k];

        ans[k]=(left*right)%k;

        for(int i=0;i<k;i++)
        {
            ans[i]=a[i];
        }

        for(int i=0;i<k;i++)
        {
            int rem=(left*i)%k;
            ans[rem]+=b[i];
        }

        return ans;
    }

    void build(vector<int>&nums,int node,int l,int r)
    {
        if(l==r)
        {
            makeLeaf(node,nums[l]);
            return;
        }

        int mid=(l+r)/2;

        build(nums,2*node,l,mid);
        build(nums,2*node+1,mid+1,r);

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    void update(int node,int l,int r,int index,int val)
    {
        if(l==r)
        {
            makeLeaf(node,val);
            return;
        }

        int mid=(l+r)/2;

        if(index<=mid)
        {
            update(2*node,l,mid,index,val);
        }
        else
        {
            update(2*node+1,mid+1,r,index,val);
        }

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    array<int,K> query(int node,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
        {
            return tree[node];
        }

        int mid=(l+r)/2;

        if(R<=mid)
        {
            return query(2*node,l,mid,L,R);
        }

        if(L>mid)
        {
            return query(2*node+1,mid+1,r,L,R);
        }

        array<int,K> left=query(2*node,l,mid,L,R);
        array<int,K> right=query(2*node+1,mid+1,r,L,R);

        return merge(left,right);
    }

    vector<int> resultArray(vector<int>&nums,int k,vector<vector<int>>&queries)
    {
        n=nums.size();
        this->k=k;

        tree.resize(4*n);

        build(nums,1,0,n-1);

        vector<int> ans;

        for(auto q:queries)
        {
            int index=q[0];
            int value=q[1];
            int start=q[2];
            int x=q[3];

            update(1,0,n-1,index,value);

            array<int,K> res=query(1,0,n-1,start,n-1);

            ans.push_back(res[x]);
        }

        return ans;
    }
};