//더 맵게

#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int,vector<int>, greater<>> q; // q의 오름차순은 greater
    for (int i = 0; i < scoville.size(); i++) {
        q.push(scoville[i]);
    }
    // 우선순위큐에 넣어서 제일 작은 수가 맨 앞으로 오도록
    
    while (q.top() < K) {
        // 제일 작은 스코빌 지수가 K보다 작다면
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();

        //cout << first << " " << second << "\n";

        int new_scov = first + (second * 2);
        //섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
        q.push(new_scov);

        answer++;

        if (q.size() == 1 && q.top() < K) {
            answer = -1;
            break;
        }
    }

    return answer;
}