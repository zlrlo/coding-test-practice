#include <string>
#include <vector>
#include <algorithm>

#define MaxNum 1000000000;

using namespace std;

int main() {
//int solution(vector<int> a) {
	vector<int> a = { -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 };
	int answer = 1;

	int alen = a.size();

	int prefixMin, suffixMin;
	int minValue = *min_element(a.begin(), a.end());
	
	prefixMin = MaxNum; 
	suffixMin = minValue; 

	for (int i = 0; i < alen; i++) {
		if (a[i] == suffixMin) break;
		if (prefixMin < a[i] && a[i] > suffixMin) continue; 
		answer += 1; 
		if (prefixMin > a[i]) prefixMin = a[i]; 
	}

	prefixMin = minValue;
	suffixMin = MaxNum;
	
	for (int i = alen - 1; i >= 0; i--) {
		if (a[i] == prefixMin) break;
		if (prefixMin < a[i] && a[i] > suffixMin) continue;
		answer += 1;
		if (suffixMin > a[i]) suffixMin = a[i];
	}
	
	int de = 1; 
	//return answer;
	return 0; 
}