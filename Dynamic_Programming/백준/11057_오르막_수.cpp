#include <iostream>
using namespace std; 

int dp[10010][10]; 

int main() {
	int n; 
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1; 
	}

	for (int y = 2; y <= n; y++) {
		for (int x = 0; x <= 9; x++) {
			for (int i = 0; i <= x; i++) {
				dp[y][x] = (dp[y][x] + dp[y - 1][i]) % 10007; 
			}
		}
	}

	int answer = 0; 
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[n][i]) % 10007; 
	}

	cout << answer; 

	return 0; 
}