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

//type�� �°� board�� ä��ų� ����(mode==1�̸� ����, mode ==-1�̸� ���)
//����� ä������ �ʴ� ��� false ��ȯ(������ �Ѿ�ų�, �̹� ä���� ���)
bool set(int y, int x, vector<vector<int>>& BlankBoard, int type, int mode)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= BlankBoard.size() || nx < 0 || nx >= BlankBoard[0].size()) // ���� �Ѿ��
        {
            ok = false;
        }
        else if ((BlankBoard[ny][nx] += mode) > 1) // �̹� ä���� ������
        {
            ok = false;
        }
    }
    return ok;
}

//ä�� �� �ִ� ����� �� ��ȯ
int NumofCases(vector<vector<int>>& BlankBoard)
{
    int y=-1;
    int x=-1;

    for(int i=0; i<BlankBoard.size(); i++)
    {
        for(int j=0; j<BlankBoard[0].size(); j++)
        {
            if(BlankBoard[i][j] == 0)    //��������� ��ġ
            {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }

    //base case: board�� �� �������� stop
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