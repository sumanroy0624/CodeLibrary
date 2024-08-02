class SegTree {
public:
	vector<ll>seg, lazy;
	SegTree(int n) {
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}
	void build(vector<ll>&a, int low, int high, int ind) {
		if (low == high) {
			seg[ind] = a[low];
			return;
		}
		int mid = (low + high) >> 1;
		build(a, low, mid, ind * 2 + 1);
		build(a, mid + 1, high, ind * 2 + 2);
		seg[ind] = min(seg[ind * 2 + 1] , seg[ind * 2 + 2]);
	}

	ll query(int low, int high, int l, int r , int ind) {
                // update the previous remaining updates
		// and propogate downwards
		if (lazy[ind] != 0) {
			seg[ind] = lazy[ind];
			if (low != high) {
				lazy[ind * 2 + 1] = lazy[ind];
				lazy[ind * 2 + 2] = lazy[ind];
			}
			lazy[ind] = 0;
		}
		// no overlap
		if (r < low || high < l)return 1e10;
		// full overlap
		else if (low >= l && high <= r) {
			return seg[ind];
		} else {
			ll mid = (low + high) >> 1;
			int left = query(low, mid, l, r, ind * 2 + 1);
			int right = query(mid + 1, high, l, r, ind * 2 + 2);
			return min(left , right);
		}
	}
	void update(int ind, int  l, int r, ll val, int low, int high) {
		// update the previous remaining updates
		// and propogate downwards
		if (lazy[ind] != 0) {
			seg[ind] = lazy[ind];
			if (low != high) {
				lazy[ind * 2 + 1] = lazy[ind];
				lazy[ind * 2 + 2] = lazy[ind];
			}
			lazy[ind] = 0;
		}
		// In no overlap cases
		// we dont do anything simply return
		// l r low high || low high l r
		if (r < low || high < l)return;
		// complete overlap
		// l low high r
		if (l <= low && high <= r) {
			seg[ind] = val;
			//  if it is not left node it will have childern
			if (low != high) {
				lazy[ind * 2 + 1] = val;
				lazy[ind * 2 + 2] = val;
			}
			return;
		}
		ll mid = (low + high) >> 1;
		update(ind * 2 + 1, l, r, val, low, mid);
		update(ind * 2 + 2, l, r, val, mid + 1, high);
		seg[ind] = min(seg[ind * 2 + 1] , seg[ind * 2 + 2]);
	}
};
