#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);

    int j = 0;
    for(int i = 1; i < patternSize; i++) {
        //j�� i��°�� j��°�� ��ġ���� ���� �� j�� �� ĭ back
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = j++;
        }
    }
    return table;
}

//haystack H�� �κ� ���ڿ��� needle N�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�.
vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;

    //pi[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
    vector<int> pi = getPartialMatch(N);

    //begin = matched = 0�������� ����
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        //haystack�� �ش� ���ڰ� needle�� �ش� ���ڿ� ���ٸ�
        if(matched < m && H[begin + matched] == N[matched]) {
            matched++;
            //m���ڰ� ��� ��ġ�ϸ� �信 �߰�
            if(matched == m) {
                ret.push_back(begin);
            }
        }
        else {
            //����: matched�� 0�� ��쿡�� ���� ĭ�������� ��� 
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                //begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
                //�ű� �Ŀ��� pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� �����̴�.
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}