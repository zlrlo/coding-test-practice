#include <iostream>
#include <algorithm>
using namespace std; 

int arr[300][300]; 
int dp[300][300]; 

int main() {
	freopen("Text.txt", "r", stdin); 

	int n; 
	cin >> n; 

	// 위
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j]; 
			if (i == 0) dp[i][j] = arr[i][j]; 
			else {
				if (j - 1 >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
				else dp[i][j] = dp[i - 1][j] + arr[i][j]; 
			}
		}
	}

	// 아래
	int limit = n + n - 1; 
	for (int i = n; i < limit; i++) {
		for (int j = 0; j < limit - i; j++) {
			cin >> arr[i][j];
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + arr[i][j];
		}
	}

	cout << dp[limit - 1][0]; 

	return 0; 
}