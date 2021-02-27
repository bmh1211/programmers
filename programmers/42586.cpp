// 기능개발

#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<int> status = progresses; // 현재진행상황

	int check_index = 0;
	bool isFinish = false;
	while (1) {
		for (int i = 0; i < progresses.size(); i++) {
			// 1초가 지날때마다 speed 만큼 진행률이 늘어남
			if (status[i] < 100) {
				status[i] += speeds[i];

				if (status[i] > 100)
					// 진행률을 더했을 때 100이 넘으면 100으로 고정
					status[i] = 100;
			}
			else
				// 이미 100으로 완성된 친구들은 패스
				continue;
		}

		if (status[check_index] == 100) {
			// 완료처리 되지 않은 것들 중 맨 앞이 100이 되면
			int finish_count = 0;
			for (int j = check_index; j < status.size(); j++) {
				if (status[j] == 100) {
					finish_count++;

					if (j == status.size() - 1) {
						// 마지막 남은 progress일 경우
						answer.push_back(finish_count);
						isFinish = true;
					}
				}
				else {
					// 체크 지점이 100이 아닌 경우
					check_index = j; // 얘가 다음 검사 시작 지점
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