#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int INF = 9999;
const int CLOCKS = 16;
const int SWITCHES = 10;

const char linked[SWITCHES][CLOCKS+1] =
{
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};


//12시에 맞춰져있는지
//clocks는 현재 시계들의 상태
bool areAlinged(const vector<int>& clocks)
{
    for(int clock = 0; clock<CLOCKS; clock++)
    {
        if(clocks[clock] != 12)
        {
            return false;
        }
    }
    return true;
}

void push(vector<int>& clocks, int swtch)   //vector는 상당히 큰 메모리 공간을 가질 수 있기 때문에 복사본으로 전달하는 것을 피해야 한다.
{
    for (int clock = 0; clock < CLOCKS; clock++)
    {
        if(linked[swtch][clock] == 'x')
        {
            clocks[clock] += 3;
            if(clocks[clock] == 15)
            {
                clocks[clock] = 3;
            }
        }
    }
}

//남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수 반환
//불가능하면 INF 반환
int solve(vector<int>& clocks, int swtch)
{
    //base case: 마지막 스위치에서 clocks가 모두 정렬되어있으면 0 반환
    if(swtch == SWITCHES)
    {
        return areAlinged(clocks) ? 0 : INF;
    }

    int ret = INF;
    for(int cnt = 0; cnt < 4; cnt++)
    {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main(void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        vector<int> clocks(16, 0);
        for(int clock = 0; clock<CLOCKS; clock++)
        {
            cin >> clocks[clock];
        }
        int answer = solve(clocks, 0);
        cout<<(answer >= INF ? -1 : answer)<<endl;
    }

    return 0;
}