#include <iostream>
using namespace std; 

long long dp[100010][3]; 

int main() {
	int n; 
	cin >> n; 

	dp[0][0] = 1; 
	dp[0][1] = 1; 
	dp[0][2] = 1; 

	for (int y = 1; y < n; y++) {
		dp[y][0] = (dp[y - 1][0] + dp[y - 1][1] + dp[y - 1][2]) % 9901; 
		dp[y][1] = (dp[y - 1][0] + dp[y - 1][2]) % 9901; 
		dp[y][2] = (dp[y - 1][0] + dp[y - 1][1]) % 9901; 		
	}

	int answer = 0;
	answer = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901; 
	cout << answer; 

	return 0; 
}