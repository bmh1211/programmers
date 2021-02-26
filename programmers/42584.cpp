// 주식가격

#include<iostream>
#include<vector>
using namespace std;

// prices_len은 배열 prices의 길이입니다.
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