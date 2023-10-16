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
  
/***
bool isFull(int H, int W, bool BlankBoard[20][20])
{
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
        {
            if(BlankBoard[i][j] == true) false;
        }
    return true;
}
***/

//type에 맞게 board를 채우거나 비운다(mode==1이면 덮고, mode ==-1이면 비움)
//제대로 채워지지 않는 경우 false 반환(범위를 넘어가거나, 이미 채워진 경우)
bool set(int y, int x, vector<vector<int>> board, int type, int mode)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) // 범위 넘어가면
        {
            ok = false;
        }
        else if ((board[ny][nx] += mode) > 1) // 이미 채워져 있으면
        {
            ok = false;
        }
    }
    return ok;
}

//채울 수 있는 경우의 수 반환
int NumofCases(vector<vector<int>> board)
{
    // 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        if (y != -1)
            break;
    }
    // 기저 사례: 모든 칸을 채웠으면 1을 반환한다
    if (y == -1)
        return 1;

    int ret = 0;
    for (int type = 0; type < 4; type++)
    {
        // 만약 board[y][x] 을 type 형태로 덮을 수 있으면 재귀호출한다
        if (set(y, x, board, type, 1))
            ret += NumofCases(board);
        // 덮었던 블록을 치운다
        set(y, x, board, type, -1);
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