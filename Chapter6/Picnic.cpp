#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

int n, m;
bool areFriends[10][10];  //���� ģ������ �Ǻ�

/***
�ߺ��� ������� ���� ���!!
bool countPairings(bool taken[10])
{
    //base case: ��� �л��� ¦�� ã�Ҵٸ� ����
    bool finished = true;
    for(int i=0; i<n; i++)
        if(!taken[i])
            finished = false;
    int ret = 0;

    //���� ģ���� �� �л��� ¦�����ֱ�
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!taken[i] && !taken[j] && areFriends[i][j])  //�� �л��� ¦�� �̹� ã�Ҵ���, ���� ģ������ ��� �Ǻ�
            {
                taken[i] = taken[j] = true;
                ret += countPairings(taken);
                taken[i] = taken[j] = false;
            }
    return ret;
}
***/

int countPairings(bool taken[10])
{
    //���� �л��� �� ���� ��ȣ�� ���� �л�
    int firstFree = -1;
    for(int i=0; i<n; i++)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }

    //base case: ��� �л��� ¦�� ã������ ����
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = (firstFree+1); pairWith < n; pairWith++) //�̹� ¦�� ã�� �л��� ��츦 skip�ϰ� Ž��
    {
        if(!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main(void)
{
    int cases;
    cin >> cases;

    while(cases--)    //cases Ƚ����ŭ �ݺ�
    {
        cin >> n >> m;
        assert(n<=10);
        memset(areFriends, 0, sizeof(areFriends));  //areFriends �迭 ��� 0���� �ʱ�ȭ
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;
            assert(0 <= a && a < n && 0 <= b && b < n);
            assert(!areFriends[a][b]);
            areFriends[a][b] = areFriends[b][a] = true;
        }
        bool taken[10];
        memset(taken, 0, sizeof(taken));
        cout << countPairings(taken) << endl;
    }
}

/***
int arr[][] -> �迭 ���·� ���� ����

assert(expression) -> expression�� false�� assert error!(���� ����)

memset(������, ������ ��, ũ��) -> 1����Ʈ ������ �ش� �ּҸ� �ʱ�ȭ
***/