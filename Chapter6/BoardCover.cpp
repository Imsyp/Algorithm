#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int coverType[4][3][2]=
{
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

//���� �� ĭ ���� ��ȯ
int NumofBlank(int H, int W, bool BlankBoard[20][20])
{
    int blank = 0;

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
        {
            if(BlankBoard[i][j] == true) blank++;
        }
    return blank;
}


//type�� �°� board�� ä��ų� ����(mode==1�̸� ����, mode ==-1�̸� ���)
//����� ä������ �ʴ� ��� false ��ȯ(������ �Ѿ�ų�, �̹� ä���� ���)
bool set(int y, int x, int H, int W, bool BlankBoard[20][20], int type, int mode)
{
    bool ok =true;
    for(int i=0; i<3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny<0 || ny>=H || nx<0 || nx>=W)  //���� �Ѿ��
            ok = false;
        else if(BlankBoard[ny][nx] != true) //�̹� ä���� ������
            ok = false;

        if(mode ==1) BlankBoard[ny][nx] = false;    //ä���
        else BlankBoard[ny][nx] = true; //����
    }
    return ok;
}

//ä�� �� �ִ� ����� �� ��ȯ
int NumofCases(int H, int W, bool BlankBoard[20][20])
{
    int ret = 0;
    int y;
    int x;

    //base case: board�� �� �������� stop
    if(NumofBlank(H, W, BlankBoard) == 0)
        return 1;

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
        {
            if(BlankBoard[i][j] == true)    //��������� ��ġ
            {
                y = i;
                x = j;
                break;
            }
        }

    for (int type = 0; type < 4; type++)
    {
        set(y, x, H, W, BlankBoard, type, 1);
        ret += NumofCases(H, W, BlankBoard);
        set(y, x, H, W, BlankBoard, type, -1);
    }

    return ret;
}

int main(void)
{
    bool BlankBoard[20][20];
    int cases, H, W;
    string Blocks;
    cin>>cases;
    while(cases--)
    {
        cin>>H>>W;
        for(int a=0; a<H; a++)
        {
            cin>>Blocks;
            for(int b=0; b<W; b++)
            {
                if(Blocks[b] == '#')
                    BlankBoard[a][b] = false;
                else
                    BlankBoard[a][b] = true;
            }
        }

        cout<<NumofCases(H, W, BlankBoard)<<endl;
    }




    return 0;
}