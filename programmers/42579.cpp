// 베스트앨범

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
    // 1. 총 노래 재생 횟수 많은 장르부터
    // 2. 장르 내에서는 재생 횟수 많은 노래부터(같을경우 고유번호 낮은것부터) 2개 선택
    // 장르로 묶음 => map 사용 / 장르 내에서 고유 번호로 나누는 map 하나 더 필요
    // 맵으로 묶은 후 벡터에 넣어서 소트
    vector<int> answer;

    map<string, int> total_play;
    for (int i = 0; i < genres.size(); i++) {
        total_play[genres[i]] += plays[i];
    }
    // 장르별 총 재생횟수

    vector<pair<string, int>> total_vector;
    map<string, int>::iterator it = total_play.begin();
    for (it; it != total_play.end(); it++) {
        total_vector.push_back(make_pair((*it).first, (*it).second));
    }
    // 정렬하기 위해 장르별 총 재생횟수를 벡터로 넣어줌

    sort(total_vector.begin(), total_vector.end(), compare_total);
    // 재생횟수가 내림차순으로 정렬됨, 맨 앞 장르가 가장 많이 플레이됨

    for (int i = 0; i < total_vector.size(); i++) {
        // 맨 앞부터 체크
        int first_max = -1, second_max = -1, first_max_index = -1, second_max_index = -1;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == total_vector[i].first) {
                // 체크할 장르와 이름이 같은 인덱스를 찾아 첫번째와 두번째로 큰 재생횟수의 인덱스 찾기
                if (plays[j] > first_max) {
                    // 가장 큰 수보다 큰 수를 찾으면 기존의 가장 큰 수를 두번째 수로 설정
                    // 가장 큰 수 대입
                    second_max = first_max;
                    first_max = plays[j];
                    second_max_index = first_max_index;
                    first_max_index = j;
                }
                else if (plays[j] > second_max) {
                    // 두번째 가장 큰 수보다는 크고 제일 큰 수보다는 작은 경우
                    second_max = plays[j];
                    second_max_index = j;
                }
            }
        }
        
        // 큰 두 수를 찾으면 answer 벡터에 대입
        // 최소 1개부터 10000개의 노래가 있으므로 최대는 반드시 존재, 두번째는 없을 수도 있으니 조건체크
        answer.push_back(first_max_index);
        if(second_max_index!= -1)
            answer.push_back(second_max_index);
    }

    return answer;
}