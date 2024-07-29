#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define print_set(s) for(auto it=s.begin(); it!=s.end(); it++){cout<<*it<<" ";}cout<<endl;
#define sv(v) sort(v.begin(),v.end())
#define rv(v) reverse(v.begin(),v.end())
#define in_vect(v) for(ll i=0;i<v.size();i++){cin>>v[i];}
#define tc(t) int t; cin >> t; while (t--)
#define ll long long
#define lli long long int
#define pb push_back
#define pob pop_back
#define ln() cout<<endl
#define cn cout<<"NO"<<endl
#define cy cout<<"YES"<<endl
#define all(v) v.begin(), v.end()
#define pv(v) for(ll i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<ll>
#define maxpq priority_queue<int>
#define minpq priority_queue<int,vector<int>,greater<int>>
int gcd(int a,int b){if(a==0) return b; return gcd(b % a, a);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int max(int a,int b){if(a>b) return a; else return b;}
int min(int a,int b){if(a<b) return a; else return b;}
bool isPrime(ll x){for(int i=2;i*i<=x;i++) if(x % i == 0) return false; return true;}
#define debug(x)cout<<#x<<' '<<x<<endl;
const int N=1e6;
vector<bool>prime(N+1,true);
void sieve(){prime[0]=false; prime[1]=false;for(int i=2;i*i<=N;i++){if(prime[i]==true){for(int j=i*i;j<=N;j+=i){prime[j]=false;}}}}
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//find_by_order, order_of_key
 
void solve(){
     ll n,k;
     cin>>n>>k;
     vi v(n);
     in_vect(v);
     vector<ll>dp(k+1,1e9);
     dp[0]=0;
     for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(v[j]<=i){
                dp[i]=min(dp[i],dp[i-v[j]]+1);
            }
        }
     }
     if(dp[k]<1e9){
        cout<<dp[k]<<endl;
     }else {
        cout<<-1<<endl;
     }
 
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // tc(t) {
         solve();
    // }
    return 0;
}
