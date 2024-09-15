#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

/*==================================== Short Hands =============================================*/

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define nl cout<<endl
#define cn cout<<"NO"<<endl
#define cy cout<<"YES"<<endl
#define ss second
#define ff first
const int mod = (long long)1e9 + 7;
#define all(v) v.begin(), v.end()
#define sv(v) sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define maxpq priority_queue<ll>
#define minpq priority_queue<ll,vector<ll>,greater<ll>>
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


/*=================================== Important Utilities ======================================*/

istream& operator>>(istream& input, vector<ll>& v) {
	for (auto& element : v) {
		input >> element;
	}
	return input;
}
#define tc(t) int t; cin >> t; while (t--)
#define ps(s) for(auto it=s.begin(); it!=s.end(); it++){cout<<*it<<" ";}cout<<endl;
#define pv(v) for(ll i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//find_by_order, order_of_key

/*=================================== Mathematical Utilities ==================================*/
ll max(ll a, ll b) {if (a >= b)return a; else return b;}
ll min(ll a, ll b) {if (a <= b)return a; else return b;}

ll exponentMod(ll x, ll y) {
	ll res = 1; x = x % mod;
	if (x == 0)return 0;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1; x = (x * x) % mod;
	}
	return res;
}

/* Factors of a number */
vector<ll>factors(ll n) {
	vector<ll>v;
	set<ll>st;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			st.insert(i);
			st.insert(n / i);
		}
	} for (auto x : st) {
		v.pb(x);
	}
	return v;
}

ll pw(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = pw(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return
	    gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
const ll N = 1e6;
vector<bool>prime(N + 1, true);
void sieve() {
	prime[0] = false;
	prime[1] = false;
	for (ll i = 2; i * i <= N; i++) {
		if (prime[i] == true)
		{
			for (ll j = i * i; j <= N; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

/*===================================== Segment Tree ==========================================*/

class SegTree {
public:
	vector<ll>seg;
	SegTree(ll n) {
		seg.resize(4 * n + 1);
	}
	void build(vector<ll>&a, ll low, ll high, ll ind) {
		if (low == high) {
			seg[ind] = a[low];
			return;
		}
		ll mid = (low + high) >> 1;
		build(a, low, mid, ind * 2 + 1);
		build(a, mid + 1, high, ind * 2 + 2);
		seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
	}

	ll query(ll low, ll high, ll l, ll r , ll ind) {
		// no overlap
		if (r < low || high < l)return 1e10;
		// full overlap
		else if (low >= l && high <= r) {
			return seg[ind];
		} else {
			ll mid = (low + high) >> 1;
			ll left = query(low, mid, l, r, ind * 2 + 1);
			ll right = query(mid + 1, high, l, r, ind * 2 + 2);
			return min(left, right);
		}
	}
	void update(ll ind, ll idx, ll val, ll low, ll high) {
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

/*====================================== Snippet Ends Here ====================================*/

struct Node {
	Node *links[26];
	bool flag = false;
	bool contains_Key(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void set_End() {
		flag = true;
	}
	bool is_End() {
		return flag;
	}
};

class Trie {
private:
	Node *root;
public:
	/**Initialize data structure Here. **/
	Trie() {
		root = new Node();
	}

	/** Insert word Into The Trie. */
	void insert(string word) {
		Node* node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch)) {
				node->put(ch, new Node());
			}

			node = node->get(ch);
		}
		node->set_End();
	}

	/** Returns if the word is Present In the Trie ! O(word.len) */
	bool search(string word) {
		Node *node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return node->is_End();
	}

	/** Return if any any word in the trie starts with prefix.  O(prefix.len) */
	bool starts_With(string prefix) {
		Node* node = root;
		for (auto ch : prefix) {
			if (!node->contains_Key(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return true;
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<string>s(n);
	for (auto &el : s)cin >> el;
	Trie t;
	for (auto el : s)t.insert(el);
	cout << t.starts_With("") << endl;

}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	tc(t) {
		solve();
	}
	return 0;
}