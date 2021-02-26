// 전화번호 목록

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> phone_book;

bool solution(vector<string> phone_book) {
    // string으로써 sort를 하면 같은 인덱스 기준 숫자 작은것이 있는 것 부터 정렬됨
    // ex) 118 118564 11898756 119 119654 11923185 처럼 되기 때문에 바로 뒤만 비교해봐도 됨
    // 바로 다음꺼의 substr이 아니면 그 다음꺼의 substr 일 수도 없음

    bool answer = true;

    sort(phone_book.begin(), phone_book.end(),less<string>());

    for (int i = 0; i < phone_book.size()-1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }

    return answer;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // test 1
    phone_book.push_back("119");
    phone_book.push_back("97674223");
    phone_book.push_back("1195524421");

    //// test 2
    //phone_book.push_back("123");
    //phone_book.push_back("456");
    //phone_book.push_back("789");

    //// test 3
    //phone_book.push_back("12");
    //phone_book.push_back("123");
    //phone_book.push_back("1235");
    //phone_book.push_back("567");
    //phone_book.push_back("88");

    cout << solution(phone_book) << "\n";

    return 0;
}