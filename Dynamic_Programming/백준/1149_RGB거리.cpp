#include <iostream>
#include <algorithm>
using namespace std; 

int priceInfo[1010][3]; 
int dp[1010][3]; 

int main() {
	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> priceInfo[i][j]; 
		}
	}

	dp[0][0] = priceInfo[0][0]; 
	dp[0][1] = priceInfo[0][1]; 
	dp[0][2] = priceInfo[0][2]; 

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int value; 
			if (j == 0) value = min(dp[i - 1][1], dp[i - 1][2]); 
			else if(j == 1) value = min(dp[i - 1][0], dp[i - 1][2]);
			else if (j == 2) value = min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][j] = priceInfo[i][j] + value; 
		}
	}

	int answer = 0; 
	answer = min(dp[n - 1][2], min(dp[n - 1][0], dp[n - 1][1])); 

	cout << answer; 

	return 0; 
}