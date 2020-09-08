#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int child_num;
	Node* next[30];
};

Node buf[2000010];
int bufCnt;

Node head[10010];
Node r_head[10010];

Node* myAlloc() {
	return &buf[bufCnt++];
}

void Insert(string& word, Node* cur, int level) {
	if (level >= word.length()) return; 

	int index = word[level] - 'a';

	if (cur->next[index] == NULL) {
		cur->next[index] = myAlloc(); 
	}
	
	cur->child_num += 1; 
	Insert(word, cur->next[index], level + 1);

	
}

int Search(string& keyword, Node* cur, int level) {

	char alpha = keyword[level]; 
	if (alpha == '?') {
		return cur->child_num; 
	}

	int index = keyword[level] - 'a';

	if (cur->next[index] == NULL) return 0; 

	int ret = Search(keyword, cur->next[index], level + 1);
	return ret; 
}

int main() {
	//vector<int> solution(vector<string> words, vector<string> queries) {
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "???????", "????o", "fr???", "fro???", "pro?" };
	vector<int> answer;

	for (auto i : words) {
		int len = i.length();
		Insert(i, &head[len], 0); 

		reverse(i.begin(), i.end());
		Insert(i, &r_head[len], 0);
	}

	for (auto i : queries) {
		int len = i.length(); 
		int ret; 

		if (i[0] != '?') {
			ret = Search(i, &head[len], 0); 
		}
		else if (i[len - 1] != '?') {
			reverse(i.begin(), i.end()); 
			ret = Search(i, &r_head[len], 0);  
		}
		else {
			ret = head[len].child_num; 
		}

		answer.push_back(ret);
	}

	//return answer;
	return 0;
}