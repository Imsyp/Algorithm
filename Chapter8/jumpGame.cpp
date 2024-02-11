#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

int cache[100][100];
int board[100][100];

//������ ���� �����ϸ� 1, �������� ���ϸ� 0 ��ȯ
int jumpGame(int y, int x, int n) {
    //base case: x, y�� board�� �������� ����� ����
    if(x >= n || y >= n) {
        return 0;
    }

    //base case: board[y][x]�� 0�̸� YES ���
    if(board[y][x] == 0) {
        cache[y][x] = 1;
        return 1;
    }


    //(y, x)�� ���� ���� ���� ���� ������ ���� ��ȯ
    int& ret = cache[y][x];
    if(ret != -1) {
        return ret;
    }

    //�Ʒ�, ���������� ������ ����
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
        //cache�迭 -1�� �ʱ�ȭ
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