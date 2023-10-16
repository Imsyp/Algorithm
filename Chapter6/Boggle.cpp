#include <iostream>
#include <vector>
#include <string>

using namespace std;

string board[5];

// y,x�� ���� �ȿ� ������ true, ���̸� false
bool inRange(int y, int x)
{
    if(y >= 0 && y < 5 && x >= 0 && x < 5)
        return true;
    else
        return false;
}

//y,x���� �����ؼ� word�� �����ϸ� true
bool hasWord(int y, int x, const string& word)
{
    //y,x�� ���� ���̸� false ��ȯ
    //y,x ��ġ�� ���ڰ� �ܾ��� ù ���ڰ� �ƴ� ��� false ��ȯ
    //word�� ���̰� 1���ڸ� true ��ȯ
    //������ ���� ���ڿ� ���ؼ� y,x�� �ֺ� ��ġ���� hasWord ����
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
        //board ä���
        for(int i = 0; i < 5; i++)
        {
            cin>>board[i];
        }

        int N;
        cin >> N;
        //N���� word ����
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