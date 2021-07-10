#include<bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double dll;
#define f(i, n) for( ll i=0 ; i<n ; i++ )
#define fa(i, a, b) for( ll i=a ; i<b ; i++ )
#define pb push_back
#define MOD 1000000007
const ll inf = 1e18 + 1;

 
void faster(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
 
 
int main() {
	faster();

	string s, t;
	cin >> s >> t;
	ll r = t.size() + 1;
	ll c = s.size() + 1;
	ll dp[r][c];
	memset(dp, 0, sizeof(dp));
	fa(i, 1, r) {
		fa(j, 1, c) {
			if(t[i-1] == s[j-1]) 
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	//cout << dp[r-1][c-1];
	
	string ans;
	ll i = r-1, j = c-1;
	while(i > 0 && j > 0) {
		if(t[i-1] == s[j-1]) {
			ans.pb(t[i-1]);
			i--;
			j--;
		} 
		else {
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	
	
}