#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
	string state; 
	string id; 
};

void split(string str, vector<string>& data) {
	int sindex = 0, findex; 

	while (1) {
		findex = str.find(' ', sindex);
		if (findex < 0) break; 

		data.push_back(str.substr(sindex, findex - sindex)); 
		sindex = findex + 1; 
	}

	data.push_back(str.substr(sindex, str.length() - sindex));
}

int main() {
//vector<string> solution(vector<string> record) {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" }; 
	vector<string> answer;

	vector<Node> dashboard; 

	unordered_map<string, string> user_info; 

	for (auto i : record) {
		vector<string> splitData; 
		split(i, splitData); 

		string state = splitData[0]; 
		string id; 
		string name; 

		if (state == "Enter") {
			id = splitData[1]; 
			name = splitData[2];

			dashboard.push_back({ state, id });

			user_info[id] = name; 
		}
		else if (state == "Leave") {
			id = splitData[1];
		
			dashboard.push_back({ state, id });
		}
		else if (state == "Change") {
			id = splitData[1];
			name = splitData[2];

			user_info[id] = name;
		}
	}

	for (auto i : dashboard) {
		string str = "";

		string name = user_info[i.id];

		if (i.state == "Enter") {
			str = name + "님이 들어왔습니다."; 
		}
		else {
			str = name + +"님이 나갔습니다."; 
		}

		answer.push_back(str); 

	}
	
	//return answer;
	return 0; 
}