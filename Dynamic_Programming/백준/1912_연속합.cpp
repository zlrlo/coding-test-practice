#include <iostream>
using namespace std; 

int arr[100010];

int main() {
	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int maxSum = -1000; 
	int sum = 0; 
	for (int i = 0; i < n; i++) {
		if (sum < 0) sum = arr[i]; 
		else sum += arr[i]; 

		if (sum > maxSum) maxSum = sum; 
	}

	cout << maxSum; 
	return 0; 
}