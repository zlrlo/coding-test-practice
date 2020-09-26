#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
	int n;
	cin >> n; 

	int num[1100]; 
	for (int i = 0; i < n; i++) {
		cin >> num[i]; 
	}

	int dp[1100] = { 0 };
	dp[0] = 1;
	int maxValue = 0; 
	for (int i = 0; i < n; i++) {
		dp[i] = 1; 
		for (int j = 0; j < i; j++) {
			if (num[j] >= num[i]) continue; 
			dp[i] = max(dp[i], dp[j] + 1); 
		}
		if (dp[i] > maxValue) maxValue = dp[i]; 
 	}

	cout << maxValue; 
	return 0; 
}