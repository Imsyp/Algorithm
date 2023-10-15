#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool board[20][20];

//남은 빈 칸 개수 반환
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

//채울 수 있는 경우의 수 반환
int NumofCases(int H, int W, bool BlankBoard[20][20])
{

}