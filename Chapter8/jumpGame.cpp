#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

int cache[100][100];
int board[100][100];

//오른쪽 끝에 도착하면 1, 도착하지 못하면 0 반환
int jumpGame(int y, int x, int n) {
    //base case: x, y가 board의 범위에서 벗어나면 종료
    if(x >= n || y >= n) {
        return 0;
    }

    //base case: board[y][x]가 0이면 YES 출력
    if(board[y][x] == 0) {
        cache[y][x] = 1;
        return 1;
    }


    //(y, x)에 대한 답을 구한 적이 있으면 곧장 반환
    int& ret = cache[y][x];
    if(ret != -1) {
        return ret;
    }

    //아래, 오른쪽으로 게임을 진행
    int dy = y + board[y][x];
    int dx = x + board[y][x];

    if(jumpGame(dy, x, n)) {
        cache[dy][x] = 1;
        return 1;
    }
    else if(jumpGame(y, dx, n)) {
        cache[y][dx] = 1;
        return 1;
    }

    cache[y][x] = 0;
    return 0;
}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases <= 50);

    while(cases--) {
        //cache배열 -1로 초기화
        memset(cache, -1, sizeof(cache));
        
        int n;
        cin >> n;
        assert(n >= 2 && n <= 100);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                if(board[i][j] == 0) {
                    break;
                }
                assert(board[i][j] >= 1 && board[i][j] <= 9);
            }
        }

        if(jumpGame(0, 0, n) == 1) {
            cout<< "YES" << endl;
        }
        else {
            cout<< "NO" << endl;
        }
    }
    return 0;
}