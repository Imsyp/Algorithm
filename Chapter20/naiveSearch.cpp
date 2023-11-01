#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> naiveSearch(const string& H, const string& N) {
    vector<int> ret;

    for(int begin = 0; begin + N.size() <= H.size(); begin++) {
        bool matched = true;
        for(int j =0; j < N.size(); j++) {
            if(H[begin+j] != N[j]) {
                matched = false;
                break;
            }
        }
        if(matched) ret.push_back(begin);
    }
    return ret;
}