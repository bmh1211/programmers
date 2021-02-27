// ���� ū ��

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool compare(string a, string b) {
	// �ٷ� �� ���� �����ٲ㰡�� ������ �� ���� �� ū�� �Ǻ�
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string>numbers_str;
	for (int i = 0; i < numbers.size(); i++) {
		numbers_str.push_back(to_string(numbers[i]));
	}

	if(numbers.size()>=2)
		sort(numbers_str.begin(), numbers_str.end(),compare);

	for (int i = 0; i < numbers_str.size(); i++){
		answer += numbers_str[i];
	}

	if (answer[0] == '0')
		// 0�� ���� ���� ��� "0000..." ó�� ����� ���͹���
		answer = "0";

	return answer;
}

int main() {
	vector<int> numbers;
	/*numbers.push_back(6);
	numbers.push_back(10);
	numbers.push_back(2);*/

	numbers.push_back(0);
	numbers.push_back(0);
	numbers.push_back(0);

	cout<< solution(numbers)<<"\n";
}