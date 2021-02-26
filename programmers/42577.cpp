// ��ȭ��ȣ ���

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> phone_book;

bool solution(vector<string> phone_book) {
    // string���ν� sort�� �ϸ� ���� �ε��� ���� ���� �������� �ִ� �� ���� ���ĵ�
    // ex) 118 118564 11898756 119 119654 11923185 ó�� �Ǳ� ������ �ٷ� �ڸ� ���غ��� ��
    // �ٷ� �������� substr�� �ƴϸ� �� �������� substr �� ���� ����

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