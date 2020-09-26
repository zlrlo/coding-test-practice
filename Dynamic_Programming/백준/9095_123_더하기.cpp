#include <iostream>
using namespace std; 

int main() {
	int t; 
	cin >> t; 

	while (t--) {
		int n; 
		cin >> n;

		int dp[20] = { 0 };

		dp[3] = 1; dp[4] = 1; dp[5] = 1; 

		for (int i = 3; i <= n + 2; i++) {
			dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3]; 
		}

		cout << dp[n + 2] << endl; 
	}

	return 0; 
}