#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool board[20][20];

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

//ä�� �� �ִ� ����� �� ��ȯ
int NumofCases(int H, int W, bool BlankBoard[20][20])
{

}