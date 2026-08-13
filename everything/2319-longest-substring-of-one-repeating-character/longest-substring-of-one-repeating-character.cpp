class Solution {
public:
    // need to learn this thing for now its eh jay gpt 
    
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char lc;
        char rc;

        Node() {
            len = pref = suff = best = 0;
            lc = rc = '#';
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if(a.len == 0) return b;
        if(b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if(a.rc == b.lc) {
            res.best = max(res.best, a.suff + b.pref);

            if(a.pref == a.len)
                res.pref = a.len + b.pref;

            if(b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int node, int l, int r, string& s) {
        if(l == r) {
            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            seg[node].lc = s[l];
            seg[node].rc = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if(l == r) {
            seg[node].lc = c;
            seg[node].rc = c;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};