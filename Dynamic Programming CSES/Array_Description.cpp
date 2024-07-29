#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
long long bs_to_decimal(const string& binaryString) { return bitset<32>(binaryString).to_ulong();}
string binary_string(long long number) {bitset<64> bits(number); return bits.to_string();}
#define print_set(s) for(auto it=s.begin(); it!=s.end(); it++){cout<<*it<<" ";}cout<<endl;
#define sv(v) sort(v.begin(),v.end())
#define rv(v) reverse(v.begin(),v.end())
#define in_vect(v) for(ll i=0;i<v.size();i++){cin>>v[i];}
#define tc(t) int t; cin >> t; while (t--)
#define ll long long
#define pb push_back
#define ln() cout<<endl
#define cn cout<<"NO"<<endl
#define cy cout<<"YES"<<endl
#define ss second
#define ff first
#define all(v) v.begin(), v.end()
#define pv(v) for(ll i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll>factors(ll n) {vector<ll>v; set<int>st; for (int i = 1; i * i <= n; i++) { if (n % i == 0) {st.insert(i); st.insert(n / i);}} for (auto x : st) {v.pb(x);} return v;}
#define maxpq priority_queue<int>
#define minpq priority_queue<int,vector<int>,greater<int>>
ll pw(ll a, ll b) {if (b == 0) return 1; ll res = pw(a, b / 2); if (b % 2)return res * res * a; else return res * res;}
int gcd(int a, int b) {if (a == 0) return b; return gcd(b % a, a);}
int lcm(int a, int b) {return a * b / gcd(a, b);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
bool isPrime(ll x) {for (int i = 2; i * i <= x; i++) if (x % i == 0) return false; return true;}
const int N = 1e6;
vector<bool>prime(N + 1, true);
void sieve() {prime[0] = false; prime[1] = false; for (int i = 2; i * i <= N; i++) {if (prime[i] == true) {for (int j = i * i; j <= N; j += i) {prime[j] = false;}}}}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//find_by_order, order_of_key
 
long long exponentMod(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
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
int mod = 1e9 + 7;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll>a(n);
    for (auto &x : a)cin >> x;
    vector<vector<ll>>dp(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= m; x++) {
            if (i == 1) {
                if (a[i - 1] == 0 || a[i - 1] == x) {
                    dp[i][x] = 1;
                } else dp[i][x] = 0;
            } else {
                if (a[i - 1] == 0 || a[i - 1] == x) {
                    dp[i][x] += (dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]) % mod;
                } else {
                    dp[i][x] = 0;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
 
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // tc(t) {
    solve();
    // }
    return 0;
}
