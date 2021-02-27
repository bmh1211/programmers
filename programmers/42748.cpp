// K번째수

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> array_sort; // 원본유지를 위해 복사본 생성
    for (int i = 0; i < commands.size(); i++) {
        array_sort.clear();

        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            array_sort.push_back(array[j]);
        }

        sort(array_sort.begin(), array_sort.end(), less<int>());
        answer.push_back(array_sort[commands[i][2] - 1]);
    }

    return answer;
}