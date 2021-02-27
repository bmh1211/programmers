// 프린터

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

	// 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
	// 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
	// 3. 그렇지 않으면 J를 인쇄합니다.
	// => 가장 큰 우선순위를 숫자로 받아서 대기목록의 맨 앞과 계속 비교
	// location이 0이면서 우선순위가 max와 맞는 경우에 출력
	
	vector<int> vec_forSort = priorities;
	sort(vec_forSort.begin(), vec_forSort.end(), greater<int>());
	int pri_max = vec_forSort[0];
	int pri_goal = priorities[location];
	int count = 0; // 인쇄횟수

	while(1) {
		if (priorities[0] == pri_max) {
			// 인쇄 대기목록의 가장 앞이 우선순위 제일 큰 문서일 때
			if (location == 0) {
				// location 0 이면 맨 앞에 있다는 뜻, 즉 내가 찾던 문서가 맨 앞에 있다는 것
				count++;
				answer = count;
			}
			else {
				// 찾던 문서가 아닌 우선순위 가장 큰 문서가 인쇄됨
				priorities.erase(priorities.begin());
				count++;

				// 새로 최우선순위 찾기
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
			// 우선순위가 밀려 인쇄하지 않고 맨 뒷 순으로 밀림
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