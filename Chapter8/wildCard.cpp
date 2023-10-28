#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

//���ϸ��� ���Ͽ� �����Ǹ� 1, �ƴϸ� 0�� ��ȯ
int match(const string& wildCard, const string& file) { 
    //file[pos]�� wildCar[pos]�� �������� ���� �� ���� (����)
    //wildCard�� ���� �����ϸ� ���� -> ���Ͽ� *�� ���� ��� (file�� ���ڿ� ���̰� ���ƾ� ��)
    //file�� ���� �����ϸ� ���� -> ������ �������� ���ڿ��� ���� ��� (���� ������ ��� *�� ��츦 �����ϰ� ���� ����)
    //wildCard[pos]�� *�� ��� ���� 
    int pos = 0;
    while(pos < file.size() && pos < wildCard.size() && (wildCard[pos] == '?' || wildCard[pos] == file[pos])) {
        pos++;
    }

    //wildCard ���� ���� �����ؼ� ���� ��� -> ���ڿ��� ������� ����
    if(pos == wildCard.size()) {
        return pos == file.size();
    }

    //*�� ������ ���� ��� -> *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ��
    if(wildCard[pos] == '*') {
        for(int skip = 0; pos+skip <= file.size(); skip++) {
            if(match(wildCard.substr(pos+1), file.substr(pos+skip))) {
                return true;
            }
        }
    }

    //�� ���� ���� ��� ����
    return false;
}

int main(void) {
    int cases;
    cin >> cases;
    assert(cases >= 1 && cases <= 10);

    while(cases--) {
        vector<string> fileZip;

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
                fileZip.push_back(file);
            }
        }

        sort(fileZip.begin(), fileZip.end());   //�ƽ�Ű �ڵ� ������ ����!

        for(int i = 0; i < fileZip.size(); i++) {
            cout << fileZip[i] << endl;
        }
    }

    return 0;
}