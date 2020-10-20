#include <iostream>
#include <algorithm>
using namespace std; 

long long dp[100010]; 

int main() {
	int n; 
	cin >> n; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; ; j++) {
			int index; 
			index = i - (j * j); 
			if (index < 0) break; 
			
			if (dp[i] == 0) dp[i] = dp[index] + 1; 
			else dp[i] = min(dp[i], dp[index] + 1); 
		}
	}

	cout << dp[n]; 

	return 0; 
}