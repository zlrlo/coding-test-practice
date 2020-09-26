#include <iostream>
using namespace std; 
#define MOD 1000000000

long long dp[110][12]; 

int main() {
	int n; 
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1; 
	}

	for (int y = 2; y <= n; y++) {
		for (int x = 0; x <= 9; x++) {
			if (x - 1 >= 0) dp[y][x] = (dp[y][x] + dp[y - 1][x - 1]) % MOD; 
			dp[y][x] = (dp[y][x] + dp[y - 1][x + 1]) % MOD; 
		}
	}

	long long answer = 0; 
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[n][i]) % MOD; 
	}

	cout << answer; 

	return 0; 
}