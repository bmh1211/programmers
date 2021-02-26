// ����

#include<iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct cloth {
	string type;
	int num;
};

int solution(vector<vector<string>> clothes) {
	// ���� ���� ������ �������� ���Ͽ� �����ϳ� �������� �ʳ��� ��츦 ���ϴ� ���� �ñ׸�
	// ex) [["û����","�ݹ���"],["�Ȱ�","��۶�","����"],["����","����"]] => [["û����","�ݹ���","����"],["�Ȱ�","��۶�","����","����"],["����","����","����"]] - 1 
	// ������ -1 �� ��ü "����"�̸� �ȵǹǷ�
	// �ǻ��� '����'�� ������ �ϱ⿡ ���ͷ� �ٷ�⿣ ������ ����
	int answer = 1;
	map<string, int> clothes_map;
	for (int i = 0; i < clothes.size(); i++) {
		clothes_map[clothes[i][1]]++;
	}

	map<string, int>::iterator it;
	// map�� �ε����� �����Ҽ� �����Ƿ� iterator �������

	for (it = clothes_map.begin(); it != clothes_map.end(); it++) {
		answer *= ((*it).second + 1);
	}

	return answer - 1;
}