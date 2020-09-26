#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000010
#define MOD 1000000009

long long dp[MAX][5]; 

int main() {
	int t; 
	cin >> t; 

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;

	for (int y = 3; y < MAX; y++) {
		dp[y][1] += (dp[y - 1][2] + dp[y - 1][3]) % MOD;
		dp[y][2] += (dp[y - 2][1] + dp[y - 2][3]) % MOD;
		dp[y][3] += (dp[y - 3][1] + dp[y - 3][2]) % MOD;
	}

	while (t--) {
		int n; 
		cin >> n;

		int answer = 0; 
		answer = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD; 

		cout << answer << endl; 
	}

	return 0; 
}