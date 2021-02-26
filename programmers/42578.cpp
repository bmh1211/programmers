// 위장

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
	// 각각 옷의 종류의 가짓수에 대하여 포함하냐 포함하지 않냐의 경우를 곱하는 것의 시그마
	// ex) [["청바지","반바지"],["안경","썬글라스","뿔테"],["반팔","긴팔"]] => [["청바지","반바지","없음"],["안경","썬글라스","뿔테","없음"],["반팔","긴팔","없음"]] - 1 
	// 마지막 -1 은 전체 "없음"이면 안되므로
	// 의상의 '종류'로 나눠야 하기에 벡터로 다루기엔 무리가 있음
	int answer = 1;
	map<string, int> clothes_map;
	for (int i = 0; i < clothes.size(); i++) {
		clothes_map[clothes[i][1]]++;
	}

	map<string, int>::iterator it;
	// map은 인덱스로 접근할수 없으므로 iterator 사용해줌

	for (it = clothes_map.begin(); it != clothes_map.end(); it++) {
		answer *= ((*it).second + 1);
	}

	return answer - 1;
}