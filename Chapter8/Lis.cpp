#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;

//������ �޾Ƽ� �ش� ������ Lis�� ��ȯ
int Lis(vector<int> seq) {
    //seq�� ����ִ� ���
    if(seq.size() == 0) {
        return 0;
    }

    vector<int> dp(500, 1);
    dp[0] = 1;

    //seq�� ��� �ε����� ���ؼ� LIS Ž��
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

        //������ ���� ��
        int N;
        cin >> N;
        assert(N <= 500);

        while(N--) {
            int elem;
            cin >> elem;
            assert(elem >= 1 && elem <= 100000);

            seq.push_back(elem);
        }

        //Lis ���� ���
        cout << Lis(seq) <<endl;
    }
}