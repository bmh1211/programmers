//모의고사

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int num1[5] = { 1, 2, 3, 4, 5 };
int num2[8] = { 2,1,2,3,2,4,2,5 };
int num3[10] = { 3,3,1,1,2,2,4,4,5,5 };
// 찍는 숫자들의 순서 한세트

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
// 내림차순 정렬

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<pair<int,int>> count; // int : count, int : person_number
    int num1_correct = 0, num2_correct = 0, num3_correct = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (num1[i%5] == answers[i])
            num1_correct++;
        if (num2[i % 8] == answers[i])
            num2_correct++;
        if (num3[i % 10] == answers[i])
            num3_correct++;
    }

    count.push_back(make_pair(num1_correct,1));
    count.push_back(make_pair(num2_correct,2));
    count.push_back(make_pair(num3_correct,3));
    // num1부터 넣었으니, 같은 값이 들어가도 1,2,3 순서로 됨

    sort(count.begin(), count.end(), compare);

    //for (int i = 0; i < count.size(); i++) {
    //    cout << count[i].second << " : " << count[i].first << "\n";
    //} // 출력테스트용

    // 제일 큰 값이 count[0]
    answer.push_back(count[0].second);

    for (int i = 1; i < count.size(); i++) {
        if (count[0].first == count[i].first)
            answer.push_back(count[i].second);
    }

    return answer;
}