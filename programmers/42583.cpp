// 다리를 지나는 트럭

#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	// truck_weights : 대기트럭
	// finish : 다리를 지난 트럭
	// crossing : 건너고 있는 트럭
	int answer = 0;

	vector<pair<int, int>> crossing;//int : 차 무게, int : 남은거리
	vector<int> finish;

	int weight_sum = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		answer++;

		// 기존의 차량들 거리 -1 씩 해주기
		for (int j = 0; j < crossing.size(); j++) {
			crossing[j].second--;

			if (crossing[j].second == 0) {
				// 기존 차량이 다리를 모두 건넌 경우
				weight_sum -= crossing[j].first;
				finish.push_back(crossing[j].first);
				crossing.erase(crossing.begin() + j);
				j--;
			}
		}
		
		weight_sum += truck_weights[i];
		if (weight_sum <= weight) {
			// 다리의 무게보다 덜 나간다면 다리위에 차량 한대 추가
			crossing.push_back(make_pair(truck_weights[i], bridge_length));
		}
		else {
			// 다리의 무게보다 더 나간다면 체크를 위해 더해줬던 차량 무게를 빼고 0을 추가 
			weight_sum -= truck_weights[i];
			crossing.push_back(make_pair(0, bridge_length));
			i--;
		}
	}

	while (!crossing.empty()) {
		// 건너는 차량이 남아있는 경우 처리해주기
		answer++;

		// 기존의 차량들 거리 -1 씩 해주기
		for (int j = 0; j < crossing.size(); j++) {
			crossing[j].second--;

			if (crossing[j].second == 0) {
				// 기존 차량이 다리를 모두 건넌 경우
				weight_sum -= crossing[j].first;
				finish.push_back(crossing[j].first);
				crossing.erase(crossing.begin() + j);
				j--;
			}
		}
	}

	return answer;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> truck_weights;

	// test1
	truck_weights.push_back(7);
	truck_weights.push_back(4);
	truck_weights.push_back(5);
	truck_weights.push_back(6);

	cout << solution(2, 10, truck_weights) << "\n";

	//// test2
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);
	//truck_weights.push_back(10);

	//cout << solution(100, 100, truck_weights) << "\n";

	// test3
	/*truck_weights.push_back(10);

	cout << solution(100, 100, truck_weights) << "\n";*/

	return 0;
}