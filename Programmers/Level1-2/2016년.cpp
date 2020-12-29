#include <string>
#include <vector>

using namespace std;

string day_of_the_week[7]; 
int month[13]; 

void initDayOfTheWeek() {
	day_of_the_week[0] = "SUN";
	day_of_the_week[1] = "MON";
	day_of_the_week[2] = "TUE";
	day_of_the_week[3] = "WED";
	day_of_the_week[4] = "THU";
	day_of_the_week[5] = "FRI";
	day_of_the_week[6] = "SAT";
}

void initMonth() {
	month[1] = 31;
	month[2] = 29;
	month[3] = 31;
	month[4] = 30;
	month[5] = 31;
	month[6] = 30;
	month[7] = 31;
	month[8] = 31;
	month[9] = 30;
	month[10] = 31;
	month[11] = 30;
	month[12] = 31;
}

int main() {
//string solution(int a, int b) {
	int a = 5;
	int b = 24; 
	string answer = "";

	initDayOfTheWeek(); 

	initMonth();

	int day = 0;

	for (int i = 1; i < a; i++) {
		day += month[i]; 
	}

	day += (b - 1) + 5;

	day %= 7; 

	answer = day_of_the_week[day]; 

	return 0; 
	//return answer;
}