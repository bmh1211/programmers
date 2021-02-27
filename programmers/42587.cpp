// ������

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

	// 1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
	// 2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
	// 3. �׷��� ������ J�� �μ��մϴ�.
	// => ���� ū �켱������ ���ڷ� �޾Ƽ� ������� �� �հ� ��� ��
	// location�� 0�̸鼭 �켱������ max�� �´� ��쿡 ���
	
	vector<int> vec_forSort = priorities;
	sort(vec_forSort.begin(), vec_forSort.end(), greater<int>());
	int pri_max = vec_forSort[0];
	int pri_goal = priorities[location];
	int count = 0; // �μ�Ƚ��

	while(1) {
		if (priorities[0] == pri_max) {
			// �μ� ������� ���� ���� �켱���� ���� ū ������ ��
			if (location == 0) {
				// location 0 �̸� �� �տ� �ִٴ� ��, �� ���� ã�� ������ �� �տ� �ִٴ� ��
				count++;
				answer = count;
			}
			else {
				// ã�� ������ �ƴ� �켱���� ���� ū ������ �μ��
				priorities.erase(priorities.begin());
				count++;

				// ���� �ֿ켱���� ã��
				vec_forSort.erase(vec_forSort.begin());
				sort(vec_forSort.begin(), vec_forSort.end(), greater<int>());
				pri_max = vec_forSort[0];

				if (location > 0)
					location--;
				else
					location += (priorities.size() - 2);
			}
		}
		else {
			// �켱������ �з� �μ����� �ʰ� �� �� ������ �и�
			priorities.push_back(priorities[0]);
			priorities.erase(priorities.begin());
			
			if (location > 0)
				location--;
			else
				location += (priorities.size() - 1);
		}

		if (answer != 0)
			break;
	}

    return answer;
}

int main() {
	vector<int> priorities; int location;
	/*priorities.push_back(2);
	priorities.push_back(1);
	priorities.push_back(3);
	priorities.push_back(2);
	location = 2;*/

	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(9);
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(1);
	location = 0;

	cout << solution(priorities, location);
}