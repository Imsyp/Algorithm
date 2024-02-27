#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string pi;
int cache[10000];
const int INF = 999999;

//a부터 b 사이의 난이도를 반환
int classify(int a, int b) {
    string subStr = pi.substr(a, b - a + 1);

    //난이도 1: 모든 숫자가 같을 때
    if(subStr == string(subStr.size(), subStr[0])) {
        return 1;
    }

    //난이도 2: 숫자가 1씩 단조 증가하거나 단조 감소할 때
    //등차 수열인지 확인
    bool ascending = true;

    for(int i = 0; i < subStr.size() - 1; i++) {
        if(subStr[i + 1] - subStr[i] != subStr[1] - subStr[0]) {
            ascending = false;
        }
    }

    //등차 수열임과 동시에 공차가 1인지 확인
    if(ascending && abs(subStr[1] - subStr[0]) == 1) {
        return 2;
    }

    //난이도 4: 두 개의 숫자가 번갈아 가며 출현할 때
    bool same = true;

    for(int i = 0; i <= 1; i++) {
        for(int j = i; j <subStr.size(); j += 2) {
            if(subStr[j] != subStr[i]) {
                same = false;
            }
        }
    }

    if(same) {
        return 4;
    }

    //난이도 5: 숫자가 등차 수열을 이룰 때
    if(ascending) {
        return 5;
    }

    //난이도 10: 그 외의 경우
    return 10;
}

//pi의 index 위치에서 끝까지의 난이도를 반환
int diff(int index) {
    //index가 pi의 범위를 넘어갈 때
    if(index > pi.size()) {
        return INF;
    }

    //base case: index가 pi의 끝에 도달
    if(index == pi.size()) {
        return 0;
    }

    //cache에 이미 값이 저장돼있으면, cache값 리턴
    int &ret = cache[index];
    if(ret != -1) {
        return ret;
    }

    //3~5씩 끊는 모든 경우의 수를 탐색
    ret = INF;
    for(int i = 3; i <= 5; i++) {
        ret = min(ret, classify(index, index + i - 1) + diff(index + i));
    }

    return ret;
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        memset(cache, -1, sizeof(cache));
        cin >> pi;

        cout << diff(0) << endl;
    }

    return 0;
}