//�� �ʰ�

#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int,vector<int>, greater<>> q; // q�� ���������� greater
    for (int i = 0; i < scoville.size(); i++) {
        q.push(scoville[i]);
    }
    // �켱����ť�� �־ ���� ���� ���� �� ������ ������
    
    while (q.top() < K) {
        // ���� ���� ���ں� ������ K���� �۴ٸ�
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();

        //cout << first << " " << second << "\n";

        int new_scov = first + (second * 2);
        //���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
        q.push(new_scov);

        answer++;

        if (q.size() == 1 && q.top() < K) {
            answer = -1;
            break;
        }
    }

    return answer;
}