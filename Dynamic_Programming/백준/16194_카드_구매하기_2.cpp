#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
	int n; 
	cin >> n; 

	int price[1100] = { 0 }; 
	for (int i = 1; i <= n; i++) {
		cin >> price[i]; 
	}

	long long dp[1100] = { 0 }; 
	for (int i = 1; i <= n; i++) {
		dp[i] = price[i]; 
		for (int j = i - 1; j >= 1; j--) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]); 
		}
	}

	cout << dp[n]; 
	return 0; 
}