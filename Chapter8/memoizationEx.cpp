/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//���� -1�� �ʱ�ȭ�� �д�
int cache[2500][2500];
//a�� b�� ���� [0, 2500) ���� ���� ����

//��ȯ ���� �׻� int�� �ȿ� ���� ���� �ƴ� ����
int someObscureFunction(int a, int b) {
    //base case
    if(. . .) {
        return . . .;
    }

    //(a, b)�� ���� ���� ���� ���� ������ ���� ��ȯ
    int& ret = cache[a][b];
    if(ret != -1) {
        return ret;
    }
    //���⼭ ���� ���
    . . .
    return ret;
}

int main(void) {
    //memset()�� �̿��� cache �迭�� �ʱ�ȭ
    memset(cache, -1, sizeof(cache));
}
*/