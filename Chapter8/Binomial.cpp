#include <iostream>

using namespace std;

int bino(int n, int r) {
    //base case: n == r (모든 원소를 다 고르는 경우) or r == 0 (고를 원소가 없는 경우)
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

    //-1이 아니라면 한 번 계산했던 값이니 곧장 반환
    if(cache[n][r] != -1) {
        return cache[n][r];
    }

    return cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}