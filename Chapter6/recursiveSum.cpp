
#include <iostream>

using namespace std;

int sum(int n)
{
    int ret = 0;
    for(int i=0; i<= n; i++)
    {
        ret += i;
    }
    return ret;
}

int recursiveSum(int n)
{
    if(n == 1) return 1;    //base case
    return n + recursiveSum(n-1);
}

int main(void)
{
    cout<<sum(10)<<" "<<recursiveSum(10)<<endl;
    return 0;
}