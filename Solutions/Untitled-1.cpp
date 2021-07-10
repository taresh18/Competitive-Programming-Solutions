#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e6+5;
 
vector< bool > primes(MAXN+5,true);
vector< int > cnt(MAXN+5,0);
void sieve() {
	primes[0] = false;
	primes[1] = false;
	for (int i=2; i*i<=MAXN; i++) {
		if (primes[i]) {
			for (int j=i*i; j<=MAXN; j+=i) {
				primes[j] = false;
			}
		}
	}
}
 
int main() {
	sieve();
	for (int i = 2; i<=MAXN; i++) {
		cnt[i] += cnt[i-1];
		if (primes[i]) {
			if (i > 10) {
 
				// check if any digit is zero
				string s = to_string(i);
				bool z = false;
				for (auto& e:s) {
					if (e == '0') z = true;
				}
				if (z) {
					continue;
				}
 
				int p = i;
				// check if all truncations are primes
				bool y = 1;
				while (p > 10) {
					s = to_string(p);
					s.erase(s.begin());
					p = stoi(s);
					y &= primes[p];
				}
				if (y) {
					cnt[i]++;
				}
			} else {
				cnt[i]++;
			}
		}
	}
 
	int t;
	cin >> t;
	for (int tt = 0; tt<t; tt++) {
		int n;
		cin >> n;
		cout << cnt[n] << '\n';
	}
	return 0;
}