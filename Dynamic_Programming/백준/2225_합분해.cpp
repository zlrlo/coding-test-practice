#include <iostream>
using namespace std; 

int n, k; 

int dp[220][220]; 

int main() {
	cin >> n >> k;

	for (int x = 0; x <= n; x++) {
		dp[1][x] = 1; 
	}

	for (int y = 2; y <= k; y++) {
		for (int x = 0; x <= n; x++) {
			for (int i = 0; i <= x; i++) {
				dp[y][x] = (dp[y][x] + dp[y - 1][x - i]) % 1000000000; 
			}
		}
	}

	cout << dp[k][n]; 

	return 0; 
}