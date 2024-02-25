#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int pi[10000];
const int INF = 99999999;
string str;

//a와 b 사이 구간의 난이도를 반환
int classify(int a, int b) {
    string subStr = str.substr(a, b - a + 1);

    //난이도 1: 모든 숫자가 같을 때
    if(subStr == string(subStr.size(), subStr[0])) {
        return 1;
    }

    //난이도 2: 1씩 단조 증가 혹은 단조 감소
    //등차 수열인지 검사
    bool progressive = true;
    for(int i = 0; i < subStr.size() - 1; i++) {
        if(subStr[i + 1] - subStr[i] != subStr[1] - subStr[0]) {
            progressive = false;
        }
    }
    //등차 수열임과 동시에, 공차가 1 혹은 -1이면 난이도 2
    if(progressive && abs(subStr[1] - subStr[0]) == 1) {
        return 2;
    }

    //난이도 4: 두 개의 숫자가 번갈아가며 등장
    bool alternating = true;
    for(int i = 0; i < subStr.size(); i++) {
        //[1 또는 0]
        if(subStr[i] != subStr[i % 2]) {
            alternating = false;
        }
    }
    if(alternating) {
        return 4;
    }

    //난이도 5: 등차 수열이기만 할 때
    if(progressive) {
        return 5;
    }

    //난이도 10: 그 외의 경우
    return 10;
}

//str의 begin 뒤 구간에서의 최소 난이도를 반환
int diff(int begin) {
    //base case: begin이 str을 넘어갈 때
    if(begin > str.size()) {
        return 99999999;
    }

    //base case: begin이 str의 끝에 도달
    if(begin == str.size()) {
        return 0;
    }

    int &ret = pi[begin];
    if(ret != -1) {
        return ret;
    }

    ret = INF;

    //쪼개는 단위는 3~5
    //3~5로 case를 나눌 때, 가장 작은 크기의 난이도를 ret로 지정
    for(int L = 3; L <= 5; L++) {
        ret = min(
            ret, classify(begin, begin + L - 1) + diff(begin + L));
    }

    return ret;
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        memset(pi, -1, sizeof(pi));
        cin >> str;
        cout << diff(0) << endl;
    }

    return 0;
}