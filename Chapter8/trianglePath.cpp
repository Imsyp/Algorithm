#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

int triSize, tri[100][100];
//cache에는 각 위치에서 나올 수 있는 최대 sum 저장
int cache[100][100];

int maxPath(int y, int x) {
    //cache에 이미 저장되어있는 경우
    int& ret = cache[y][x];
    if(ret != -1) {
        return ret;
    }

    //base case: 마지막 줄
    if(y == triSize - 1) {
        return tri[y][x];
    }

    //현재 위치의 최대값 cache에 저장    
    return ret = tri[y][x] + max(maxPath(y + 1, x), maxPath(y + 1, x + 1));
}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases <= 50);

    while(cases--) {
        //cache배열 -1로 초기화
        memset(cache, -1, sizeof(cache));

        cin >> triSize;
        assert(triSize >= 2 && triSize <= 100);

        //triangle 생성
        for(int y = 0; y < triSize; y++) {
            for(int x = 0; x <= y; x++) {
                int num;
                cin >> num;
                assert(num >= 1 && num <= 100000);

                tri[y][x] = num;
            }
        }

        //최대 경로 계산
        cout << maxPath(0, 0) << endl;
    }
}