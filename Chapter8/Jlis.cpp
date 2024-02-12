#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

//수열 A와 B를 입력을 받아, JLIS 길이 반환
int JLIS(vector<int> A, vector<int> B) {


    return .size();
}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases >= 1 && cases <= 50);

    while(cases--) {
        vector<int> A, B;

        int n, m;
        cin >> n >> m;
        assert(n >=1 && n <= 100);
        assert(m >=1 && m <= 100);

        //n개의 A의 원소 입력
        while(n--) {
            int elem;
            cin >> elem;
            
            A.push_back(elem);
        }

        //m개의 B의 원소 입력
        while(m--) {
            int elem;
            cin >> elem;
            
            B.push_back(elem);
        }

        //A와 B의 JLIS 길이 계산
        cout << JLIS(A, B) << endl;
    }

    return 0;
}
