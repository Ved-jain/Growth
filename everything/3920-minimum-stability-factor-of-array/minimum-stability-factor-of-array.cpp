class Solution {
public:
    vector<int> seg;
    int n;

    void build(int idx, int l, int r, vector<int>& nums) {

        if(l == r) {
            seg[idx] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, nums);
        build(2 * idx + 1, mid + 1, r, nums);

        seg[idx] = gcd(seg[2 * idx], seg[2 * idx + 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {

        //inside
        if(ql <= l && r <= qr)
            return seg[idx];

        // outisde
        if(r < ql || l > qr)
            return 0;
        // partial wali condition 
        int mid = (l + r) / 2;

        int left = query(2 * idx, l, mid, ql, qr);
        int right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return gcd(left, right);
    }

    bool check(int len, vector<int>& nums, int maxC) {

        int window = len + 1;

        if(window > n)
            return true;

        int changes = 0;
        int last = -1;

        for(int i = 0; i + window <= n; i++) {

            int j = i + window - 1;

            int g = query(1, 0, n - 1, i, j);

            if(g >= 2) {

                
                if(last >= i)
                    continue;

               
                changes++;
                last = j;

                if(changes > maxC)
                    return false;
            }
        }

        return true;
    }

    int minStable(vector<int>& nums, int maxC) {

        n = nums.size();

        seg.assign(4 * n, 0);

        build(1, 0, n - 1, nums);

        int low = 0;
        int high = n;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(check(mid, nums, maxC))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};