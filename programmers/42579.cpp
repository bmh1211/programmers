// ����Ʈ�ٹ�

#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include <iostream>

using namespace std;

bool compare_total(pair<string,int> a,pair<string,int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 1. �� �뷡 ��� Ƚ�� ���� �帣����
    // 2. �帣 �������� ��� Ƚ�� ���� �뷡����(������� ������ȣ �����ͺ���) 2�� ����
    // �帣�� ���� => map ��� / �帣 ������ ���� ��ȣ�� ������ map �ϳ� �� �ʿ�
    // ������ ���� �� ���Ϳ� �־ ��Ʈ
    vector<int> answer;

    map<string, int> total_play;
    for (int i = 0; i < genres.size(); i++) {
        total_play[genres[i]] += plays[i];
    }
    // �帣�� �� ���Ƚ��

    vector<pair<string, int>> total_vector;
    map<string, int>::iterator it = total_play.begin();
    for (it; it != total_play.end(); it++) {
        total_vector.push_back(make_pair((*it).first, (*it).second));
    }
    // �����ϱ� ���� �帣�� �� ���Ƚ���� ���ͷ� �־���

    sort(total_vector.begin(), total_vector.end(), compare_total);
    // ���Ƚ���� ������������ ���ĵ�, �� �� �帣�� ���� ���� �÷��̵�

    for (int i = 0; i < total_vector.size(); i++) {
        // �� �պ��� üũ
        int first_max = -1, second_max = -1, first_max_index = -1, second_max_index = -1;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == total_vector[i].first) {
                // üũ�� �帣�� �̸��� ���� �ε����� ã�� ù��°�� �ι�°�� ū ���Ƚ���� �ε��� ã��
                if (plays[j] > first_max) {
                    // ���� ū ������ ū ���� ã���� ������ ���� ū ���� �ι�° ���� ����
                    // ���� ū �� ����
                    second_max = first_max;
                    first_max = plays[j];
                    second_max_index = first_max_index;
                    first_max_index = j;
                }
                else if (plays[j] > second_max) {
                    // �ι�° ���� ū �����ٴ� ũ�� ���� ū �����ٴ� ���� ���
                    second_max = plays[j];
                    second_max_index = j;
                }
            }
        }
        
        // ū �� ���� ã���� answer ���Ϳ� ����
        // �ּ� 1������ 10000���� �뷡�� �����Ƿ� �ִ�� �ݵ�� ����, �ι�°�� ���� ���� ������ ����üũ
        answer.push_back(first_max_index);
        if(second_max_index!= -1)
            answer.push_back(second_max_index);
    }

    return answer;
}