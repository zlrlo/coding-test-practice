﻿#include <iostream>
using namespace std; 

long long dp[1000010]; 

int main() {
	int tcase; 
	cin >> tcase; 

	dp[1] = 1; 
	dp[2] = 2; 
	dp[3] = 4; 
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
		dp[i] %= 1000000009; 
	}

	while (tcase--) {
		int n; 
		cin >> n;

		cout << dp[n] << endl; 
	}

	return 0; 
}