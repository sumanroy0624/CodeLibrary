class SegTree {
public:
	vector<ll>seg, lazy;
	SegTree(int n) {
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}
	void build(vector<ll>&a, ll low, ll high, ll ind) {
		if (low == high) {
			seg[ind] = a[low];
			return;
		}
		ll mid = (low + high) >> 1;
		build(a, low, mid, ind * 2 + 1);
		build(a, mid + 1, high, ind * 2 + 2);
		seg[ind] = (seg[ind * 2 + 1] + seg[ind * 2 + 2]);
	}

	ll query(ll low, ll high, ll l, ll r , ll ind) {
		// no overlap
		if (lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];
			if (low != high) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
		if (r < low || high < l)return 0;
		// full overlap
		else if (low >= l && high <= r) {
			return seg[ind];
		} else {
			ll mid = (low + high) >> 1;
			ll left = query(low, mid, l, r, ind * 2 + 1);
			ll right = query(mid + 1, high, l, r, ind * 2 + 2);
			return (left + right);
		}
	}
	void update(ll ind, ll  l, ll r, ll val, ll low, ll high) {
		// update the previous remaining updates
		// and propogate downwards
		if (lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];
			if (low != high) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
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
			seg[ind] += (high - low + 1) * val;
			//  if it is not left node it will have childern
			if (low != high) {
				lazy[ind * 2 + 1] += val;
				lazy[ind * 2 + 2] += val;
			}
			return;
		}
		ll mid = (low + high) >> 1;
		update(ind * 2 + 1, l, r, val, low, mid);
		update(ind * 2 + 2, l, r, val, mid + 1, high);
		seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
	}
};
