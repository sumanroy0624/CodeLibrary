#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1e9 + 7;
 
 
int main() {
	int n, k;
	cin >> n >> k;
	int dp[k + 1];
	int arr[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] += dp[i - arr[j]];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[k] << endl;
}
