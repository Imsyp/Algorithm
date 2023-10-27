#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//파일명이 패턴에 대응되면 1, 아니면 0을 반환
int match(const string& wildCard, const string& file) {
    //base case: 
}

int main(void)
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