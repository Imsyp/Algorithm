#include <iostream>
#include <vector>
#include <string>

using namespace std;

//num[]의 자릿수 올림 처리
void normalize(vector<int>& num)
{
    num.push_back(0);

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < 0)
        {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int> b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); i++)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k);
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    int an = a.size(), bn = b.size();
}