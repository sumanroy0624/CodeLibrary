class SegTree {
public:
    vector<ll>seg;
    SegTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(vector<ll>&a, int low, int high, int ind) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(a, low, mid, ind * 2 + 1);
        build(a, mid + 1, high, ind * 2 + 2);
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    ll query(int low, int high, int l, int r , int ind) {
        // no overlap
        if (r < low || high < l)return 1e10;
        // full overlap
        else if (low >= l && high <= r) {
            return seg[ind];
        } else {
            ll mid = (low + high) >> 1;
            int left = query(low, mid, l, r, ind * 2 + 1);
            int right = query(mid + 1, high, l, r, ind * 2 + 2);
            return min(left, right);
        }
    }
    void update(int ind, int idx, ll val, int low, int high) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        ll mid = (low + high) >> 1;
        if (idx <= mid)update(ind * 2 + 1, idx, val, low, mid);
        else update(ind * 2 + 2, idx, val, mid + 1, high);
        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }
};
