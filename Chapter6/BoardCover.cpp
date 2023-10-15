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
bool set(int y, int x, int H, int W, vector<vector<int>>& BlankBoard, int type, int mode)
{
    bool ok =true;
    for(int i=0; i<3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny<0 || ny>=H || nx<0 || nx>=W)  //범위 넘어가면
            ok = false;
        else if(BlankBoard[ny][nx] != true) //이미 채워져 있으면
            ok = false;

        if(mode ==1) 
            BlankBoard[ny][nx] = 0;   //채우기
        else 
            BlankBoard[ny][nx] = 1; //비우기
        cout<<2<<endl;
    }
    return ok;
}

//채울 수 있는 경우의 수 반환
int NumofCases(int H, int W, vector<vector<int>>& BlankBoard)
{
    int ret = 0;
    int y=-1;
    int x=-1;

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
        {
            if(BlankBoard[i][j] == 1)    //최좌측상단 위치
            {
                y = i;
                x = j;
                break;
            }
        }

    //base case: board가 꽉 차있으면 stop
    if(y == -1)
        return 1;

    for (int type = 0; type < 4; type++)
    {
        if(set(y, x, H, W, BlankBoard, type, 1)==true);
        {
            ret += NumofCases(H, W, BlankBoard);
        }
        set(y, x, H, W, BlankBoard, type, -1);
    }

    return ret;
}

int main(void)
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int H, W;
        cin>>H>>W;
        vector<vector<int>> BlankBoard(H, vector<int>(W, 1));
        for(int a=0; a<H; a++)
        {
            string Blocks;
            cin>>Blocks;
            for(int b=0; b<W; b++)
            {
                if(Blocks[b] == '#')
                    BlankBoard[a][b] = 0;
                else
                    BlankBoard[a][b] = 1;
            }
        }
        cout<<NumofCases(H, W, BlankBoard)<<endl;
    }

    return 0;
}