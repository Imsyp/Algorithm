#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

int n, m;
bool areFriends[10][10];  //둘이 친구인지 판별

/***
중복을 고려하지 않은 경우!!
bool countPairings(bool taken[10])
{
    //base case: 모든 학생이 짝을 찾았다면 종료
    bool finished = true;
    for(int i=0; i<n; i++)
        if(!taken[i])
            finished = false;
    int ret = 0;

    //서로 친구인 두 학생을 짝지어주기
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!taken[i] && !taken[j] && areFriends[i][j])  //두 학생이 짝을 이미 찾았는지, 서로 친구인지 모두 판별
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
    //남은 학생들 중 가장 번호가 빠른 학생
    int firstFree = -1;
    for(int i=0; i<n; i++)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }

    //base case: 모든 학생이 짝을 찾았으면 종료
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = (firstFree+1); pairWith < n; pairWith++) //이미 짝을 찾은 학생의 경우를 skip하고 탐색
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

    while(cases--)    //cases 횟수만큼 반복
    {
        cin >> n >> m;
        assert(n<=10);
        memset(areFriends, 0, sizeof(areFriends));  //areFriends 배열 모두 0으로 초기화
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
int arr[][] -> 배열 형태로 접근 가능

assert(expression) -> expression이 false면 assert error!(오류 검출)

memset(포인터, 설정할 값, 크기) -> 1바이트 단위로 해당 주소를 초기화
***/