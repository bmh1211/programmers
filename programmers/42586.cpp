// ��ɰ���

#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<int> status = progresses; // ���������Ȳ

	int check_index = 0;
	bool isFinish = false;
	while (1) {
		for (int i = 0; i < progresses.size(); i++) {
			// 1�ʰ� ���������� speed ��ŭ ������� �þ
			if (status[i] < 100) {
				status[i] += speeds[i];

				if (status[i] > 100)
					// ������� ������ �� 100�� ������ 100���� ����
					status[i] = 100;
			}
			else
				// �̹� 100���� �ϼ��� ģ������ �н�
				continue;
		}

		if (status[check_index] == 100) {
			// �Ϸ�ó�� ���� ���� �͵� �� �� ���� 100�� �Ǹ�
			int finish_count = 0;
			for (int j = check_index; j < status.size(); j++) {
				if (status[j] == 100) {
					finish_count++;

					if (j == status.size() - 1) {
						// ������ ���� progress�� ���
						answer.push_back(finish_count);
						isFinish = true;
					}
				}
				else {
					// üũ ������ 100�� �ƴ� ���
					check_index = j; // �갡 ���� �˻� ���� ����
					answer.push_back(finish_count);
					break;
				}
			}
		}

		if (isFinish)
			break;
	}

	return answer;
}

int main() {
	vector<int> progresses; vector<int> speeds; vector<int> answer;
	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);

	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);

	answer = solution(progresses, speeds);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}