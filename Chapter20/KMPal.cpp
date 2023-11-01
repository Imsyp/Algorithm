#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string pattern) {
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