// �ٸ��� ������ Ʈ��

#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	// truck_weights : ���Ʈ��
	// finish : �ٸ��� ���� Ʈ��
	// crossing : �ǳʰ� �ִ� Ʈ��
	int answer = 0;

	vector<pair<int, int>> crossing;//int : �� ����, int : �����Ÿ�
	vector<int> finish;

	int weight_sum = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		answer++;

		// ������ ������ �Ÿ� -1 �� ���ֱ�
		for (int j = 0; j < crossing.size(); j++) {
			crossing[j].second--;

			if (crossing[j].second == 0) {
				// ���� ������ �ٸ��� ��� �ǳ� ���
				weight_sum -= crossing[j].first;
				finish.push_back(crossing[j].first);
				crossing.erase(crossing.begin() + j);
				j--;
			}
		}
		
		weight_sum += truck_weights[i];
		if (weight_sum <= weight) {
			// �ٸ��� ���Ժ��� �� �����ٸ� �ٸ����� ���� �Ѵ� �߰�
			crossing.push_back(make_pair(truck_weights[i], bridge_length));
		}
		else {
			// �ٸ��� ���Ժ��� �� �����ٸ� üũ�� ���� ������� ���� ���Ը� ���� 0�� �߰� 
			weight_sum -= truck_weights[i];
			crossing.push_back(make_pair(0, bridge_length));
			i--;
		}
	}

	while (!crossing.empty()) {
		// �ǳʴ� ������ �����ִ� ��� ó�����ֱ�
		answer++;

		// ������ ������ �Ÿ� -1 �� ���ֱ�
		for (int j = 0; j < crossing.size(); j++) {
			crossing[j].second--;

			if (crossing[j].second == 0) {
				// ���� ������ �ٸ��� ��� �ǳ� ���
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