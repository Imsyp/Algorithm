#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//파일명이 패턴에 대응되면 1, 아니면 0을 반환
int match(const string& wildCard, const string& file) {
    //base case: 

    //file[pos]와 wildCar[pos]가 대응되지 않을 때 종료 (거짓)
    //wildCard의 끝에 도달하면 종료 -> 패턴에 *가 없는 경우 (file과 문자열 길이가 같아야 참)
    //file의 끝에 도달하면 종료 -> 패턴은 남았지만 문자열이 끝난 경우 (남은 패턴이 모두 *인 경우를 제외하고 답은 거짓)
    //wildCard[pos]가 *인 경우 종료 
    int pos = 0;
    while(pos < file.size() && pos < wildCard.size() && (wildCard[pos] == '?' || wildCard[pos] == file[pos])) {
        pos++;
    }
}

bool main(void)
{
    int cases;
    cin >> cases;
    assert(cases >= 1 && cases <= 10);

    while(cases--) {
        string fileZip[50];

        string W;
        cin >> W;
        assert(W.size() >= 1 && W.size() <=100);

        int N;
        cin >> N;
        assert(N >= 1 && N <= 50);

        for(int i = 0; i < N; i++) {
            string file;
            cin >> file;
            assert(file.size() >= 1 && file.size() <= 100);
            if(match(W, file)) {
                fileZip[i] = file;
            }
        }
    }
}