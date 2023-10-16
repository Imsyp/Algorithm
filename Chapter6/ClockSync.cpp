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


//12�ÿ� �������ִ���
//clocks�� ���� �ð���� ����
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

void push(vector<int>& clocks, int swtch)   //vector�� ����� ū �޸� ������ ���� �� �ֱ� ������ ���纻���� �����ϴ� ���� ���ؾ� �Ѵ�.
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

//���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ�� ��ȯ
//�Ұ����ϸ� INF ��ȯ
int solve(vector<int>& clocks, int swtch)
{
    //base case: ������ ����ġ���� clocks�� ��� ���ĵǾ������� 0 ��ȯ
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