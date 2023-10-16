#include<numeric>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int coverType[4][3][2] = {
  { { 0, 0 }, { 1, 0 }, { 0, 1 } },
  { { 0, 0 }, { 0, 1 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, -1 } }};

//type에 맞게 board를 채우거나 비운다(mode==1이면 덮고, mode ==-1이면 비움)
//제대로 채워지지 않는 경우 false 반환(범위를 넘어가거나, 이미 채워진 경우)
bool set(int y, int x, vector<vector<int>>& BlankBoard, int type, int mode)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= BlankBoard.size() || nx < 0 || nx >= BlankBoard[0].size()) // 범위 넘어가면
        {
            ok = false;
        }
        else if ((BlankBoard[ny][nx] += mode) > 1) // 이미 채워져 있으면
        {
            ok = false;
        }
    }
    return ok;
}

//채울 수 있는 경우의 수 반환
int NumofCases(vector<vector<int>>& BlankBoard)
{
    int y=-1;
    int x=-1;

    for(int i=0; i<BlankBoard.size(); i++)
    {
        for(int j=0; j<BlankBoard[0].size(); j++)
        {
            if(BlankBoard[i][j] == 0)    //최좌측상단 위치
            {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }

    //base case: board가 꽉 차있으면 stop
    if (y == -1)
        return 1;

    int ret = 0;

    for (int type = 0; type < 4; type++)
    {
        if (set(y, x, BlankBoard, type, 1));
        {
            ret += NumofCases(BlankBoard);
        }
        set(y, x, BlankBoard, type, -1);
    }
    return ret;
}

int main(void)
{
    int cases;
    cin>>cases;
    for(int cc=0; cc<cases; cc++)
    {
        int H, W;
        cin >>H>>W;
        assert(1 <= H && H <= 20);
        assert(1 <= W && W <= 20);
        vector<vector<int>> BlankBoard(H, vector<int>(W, 0));
        for(int a=0; a<H; a++)
        {
            string Blocks;
            cin>>Blocks;
            for(int b=0; b<W; b++)
            {
                if(Blocks[b] == '#')
                    BlankBoard[a][b] = 1;
            }
        }

        int numCases = NumofCases(BlankBoard);
        cout << numCases << endl;
    }
    return 0;
}