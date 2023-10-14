#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;
 
int ny[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int nx[8] = {  0,  1, 1, 1, 0,-1,-1, -1 };
string board[5];
bool Findword(const string& s, int y, int x) {
    //기저사례 범위 밖을 벗어나는 경우
    if (y < 0 || y >= 5 || x < 0 || x >= 5) return false;
    //기저사례 첫글자가 일치하지 않으면 실패
    if (board[y][x]!=s[0]) return false;
    //기저사례 단어길이가 1이면 성공
    if (s.size() == 1) return true;
 
    for (int direction = 0; direction < 8; direction++) {
        int Nexty = y + ny[direction];
        int Nextx = x + nx[direction];
        if (Findword(s.substr(1), Nexty, Nextx))
            return true;
    }
    return false;
}
 
int main()
{
    int cases;
    cin >> cases;
    assert(cases <= 50);
    while (cases) 
    {
        for (int i = 0; i < 5; i++) 
        {
            cin >> board[i];
        }
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) 
        {
            bool Check = false;
            string s;
            cin >> s;

            for (int a = 0; a < 5; a++) 
            {
                for (int b = 0; b < 5; b++) 
                {
                    if (board[a][b] == s[0]) 
                    {
                        Check = Findword(s, a, b);
                        if (Check)
                            break;
                    }
                }
                if (Check)
                    break;
            }
            if (Check)
                cout << s << " " << "YES\n";
            else
                cout << s << " " << "NO\n";
                
        }
        cases--;
    }
    return 0;
}
/***
다중 인덱싱

문제 이해 자체를 못함!!!!

8장 배우고 다시 풀어보자
***/