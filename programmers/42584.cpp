// �ֽİ���

#include<iostream>
#include<vector>
using namespace std;

// prices_len�� �迭 prices�� �����Դϴ�.
vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());

	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] <= prices[j])
				answer[i]++;
			else {
				answer[i]++;
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(3);

	vector<int> result = solution(prices);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}