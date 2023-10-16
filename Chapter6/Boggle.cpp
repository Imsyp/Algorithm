#include <iostream>
#include <vector>
#include <string>

using namespace std;

string board[5];

// y,x가 범위 안에 있으면 true, 밖이면 false
bool inRange(int y, int x)
{
    if(y >= 0 && y < 5 && x >= 0 && x < 5)
        return true;
    else
        return false;
}

//y,x에서 시작해서 word가 존재하면 true
bool hasWord(int y, int x, const string& word)
{
    //y,x가 범위 밖이면 false 반환
    //y,x 위치의 글자가 단어의 첫 글자가 아닌 경우 false 반환
    //word의 길이가 1글자면 true 반환
    //검증한 다음 글자에 대해서 y,x의 주변 위치에서 hasWord 실행
    if(!inRange(y, x))
        return false;
    else if(board[y][x] != word[0])
        return false;   
    else if(word.size() == 1)
        return true;
    else
    {    
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (hasWord(y + i, x + j, word.substr(1)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    int C;
    cin >> C;

    while(C--)
    {
        //board 채우기
        for(int i = 0; i < 5; i++)
        {
            cin>>board[i];
        }

        int N;
        cin >> N;
        //N개의 word 검증
        for(int n = 0; n < N; n++)
        {
            bool Check = false;
            string word;
            cin >> word;
            for(int a = 0; a < 5; a++)
            {
                for(int b = 0; b < 5; b++)
                {
                    Check = hasWord(a, b, word);
                    if(Check)
                    {
                        break;
                    }
                }
                if(Check)
                {
                    break;
                }
            }
            if(Check)
            {
                cout << word << " YES" << endl;
            }
            else
            {
                cout<< word << " NO" << endl;
            }
        }
    }
    return 0;
}