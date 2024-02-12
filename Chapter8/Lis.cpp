#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;

//수열을 받아서 해당 수열의 Lis를 반환
int Lis(vector<int> seq) {
    //seq가 비어있는 경우
    if(seq.size() == 0) {
        return 0;
    }

    vector<int> dp(500, 1);
    dp[0] = 1;

    //seq의 모든 인덱스에 대해서 LIS 탐색
    for(int i = 1; i < seq.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(seq[i] > seq[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.begin() + seq.size());

}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases <= 50);

    while(cases--) {
        vector<int> seq;

        //수열의 원소 수
        int N;
        cin >> N;
        assert(N <= 500);

        while(N--) {
            int elem;
            cin >> elem;
            assert(elem >= 1 && elem <= 100000);

            seq.push_back(elem);
        }

        //Lis 길이 출력
        cout << Lis(seq) <<endl;
    }
}