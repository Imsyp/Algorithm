#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

//���� A�� B�� �Է��� �޾�, JLIS ���� ��ȯ
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

        //n���� A�� ���� �Է�
        while(n--) {
            int elem;
            cin >> elem;
            
            A.push_back(elem);
        }

        //m���� B�� ���� �Է�
        while(m--) {
            int elem;
            cin >> elem;
            
            B.push_back(elem);
        }

        //A�� B�� JLIS ���� ���
        cout << JLIS(A, B) << endl;
    }

    return 0;
}
