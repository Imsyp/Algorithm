#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

int triSize, tri[100][100];
//cache���� �� ��ġ���� ���� �� �ִ� �ִ� sum ����
int cache[100][100];

int maxPath(int y, int x) {
    //cache�� �̹� ����Ǿ��ִ� ���
    int& ret = cache[y][x];
    if(ret != -1) {
        return ret;
    }

    //base case: ������ ��
    if(y == triSize - 1) {
        return tri[y][x];
    }

    //���� ��ġ�� �ִ밪 cache�� ����    
    return ret = tri[y][x] + max(maxPath(y + 1, x), maxPath(y + 1, x + 1));
}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases <= 50);

    while(cases--) {
        //cache�迭 -1�� �ʱ�ȭ
        memset(cache, -1, sizeof(cache));

        cin >> triSize;
        assert(triSize >= 2 && triSize <= 100);

        //triangle ����
        for(int y = 0; y < triSize; y++) {
            for(int x = 0; x <= y; x++) {
                int num;
                cin >> num;
                assert(num >= 1 && num <= 100000);

                tri[y][x] = num;
            }
        }

        //�ִ� ��� ���
        cout << maxPath(0, 0) << endl;
    }
}