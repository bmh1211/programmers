// �������� ���� ����

#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<string> participant;
vector<string> completion;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	// �����ؼ� �տ������� ���������ٰ� �ٸ��κ� ã��(ũ������ 1 �̹Ƿ� ����)
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
		else if (i == completion.size() - 1)
			answer = participant[i + 1];
	}

	return answer;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");

	completion.push_back("eden");
	completion.push_back("kiki");

	cout << solution(participant, completion);

	return 0;
}