#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);

    int j = 0;
    for(int i = 1; i < patternSize; i++) {
        //j를 i번째와 j번째가 일치하지 않을 때 j를 한 칸 back
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = j++;
        }
    }
    return table;
}

//haystack H의 부분 문자열로 needle N이 출현하는 시작 위치들을 모두 반환한다.
vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;

    //pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
    vector<int> pi = getPartialMatch(N);

    //begin = matched = 0에서부터 시작
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        //haystack의 해당 글자가 needle의 해당 글자와 같다면
        if(matched < m && H[begin + matched] == N[matched]) {
            matched++;
            //m글자가 모두 일치하면 답에 추가
            if(matched == m) {
                ret.push_back(begin);
            }
        }
        else {
            //예외: matched가 0인 경우에는 다음 칸에서부터 계속 
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                //begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
                //옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문이다.
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}