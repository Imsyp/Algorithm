#include <iostream>

using namespace std;

int bino(int n, int r) {
    //base case: n == r (��� ���Ҹ� �� ���� ���) or r == 0 (�� ���Ұ� ���� ���)
    if(r == 0 || n == r) {
        return 1;
    }

    return bino(n-1, r-1) + bino(n-1, r);
}

int cache[30][30];
int bino2(int n, int r) {
    //base case
    if(r == 0 || n == r) {
        return 1;
    }

    //-1�� �ƴ϶�� �� �� ����ߴ� ���̴� ���� ��ȯ
    if(cache[n][r] != -1) {
        return cache[n][r];
    }

    return cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}