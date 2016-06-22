#include <iostream>
#define rep(i, m) for(int i=0;i<m;i++)
#define M 1000000007

using namespace std;

long long dp[201][201];
int main() {
	int n;
	char c[201];

	cin >> n;
	rep (i, n) cin >> c[i];

	dp[0][0] = 1;
	rep (i, n) {
		if (c[i] == '-') rep(j, n+1) dp[i+1][j] = dp[i][j];
		else {
			rep (j, i+1) {
				if (c[i] == 'D') {
					if (j) dp[i+1][j-1] += (j*((j*dp[i][j])%M))%M;
					dp[i+1][j-1] %= M;
				} else {
					dp[i+1][j+1] += dp[i][j];
					dp[i+1][j+1] %= M;
				}
				dp[i+1][j] += (j*dp[i][j])%M;
				dp[i+1][j] %= M;
			}
		}
	}

	cout << dp[n][0] << endl;
	return 0;
}
