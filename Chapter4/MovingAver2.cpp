#include <iostream>
#include <vector>

using namespace std;

vector <double> movingAverage1(const vector<double>& A, int M)
{
    vector<double> ret;
    int N = A.size();
    for(int i = M-1; i<N; i++)
    {
        double partialSum=0;
        for(int j=0; j<M; j++)
            partialSum+=A[i-j];
        ret.push_back(partialSum/M);
    }
}