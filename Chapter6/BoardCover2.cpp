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

//type�� �°� board�� ä��ų� ����(mode==1�̸� ����, mode ==-1�̸� ���)
//����� ä������ �ʴ� ��� false ��ȯ(������ �Ѿ�ų�, �̹� ä���� ���)
bool set(int y, int x, vector<vector<int>> board, int type, int mode)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) // ���� �Ѿ��
        {
            ok = false;
        }
        else if ((board[ny][nx] += mode) > 1) // �̹� ä���� ������
        {
            ok = false;
        }
    }
    return ok;
}

//ä�� �� �ִ� ����� �� ��ȯ
int NumofCases(vector<vector<int>> board)
{
    // ���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�
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
    // ���� ���: ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�
    if (y == -1)
        return 1;

    int ret = 0;
    for (int type = 0; type < 4; type++)
    {
        // ���� board[y][x] �� type ���·� ���� �� ������ ���ȣ���Ѵ�
        if (set(y, x, board, type, 1))
            ret += NumofCases(board);
        // ������ ����� ġ���
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