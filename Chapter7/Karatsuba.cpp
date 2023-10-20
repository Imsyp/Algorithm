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
        if (num[i] < 0) //음수인 경우의 처리 -> 카라츠바 구현 후 이해 가능
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
    vector<int> c(a.size() + b.size() + 1, 0);  //가능한 최대 자릿수
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); i++)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}

//a += b * (10^k);를 구현
void addTo(vector<int>& a, const vector<int>& b, int k);

//a -= b;를 구현 (a >= b 가정) 
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();

    //a가 b보다 짧을 경우 둘을 바꾼다.
    if(an < bn) {
        return karatsuba(b, a);
    }

    //base case: a나 b가 비어있는 경우
    if(an == 0 || bn == 0) {
        return vector<int>();
    }

    //base case: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
    if(an <= 50) {
        return multiply(a, b);
    }

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);    //a.begin() ~ (a.begin() + half - 1)
    vector<int> a1(a.begin() + half, a.end());      //(a.begin() + half) ~ (a.end() -1) -> a.end(): 끝 요소 + 1
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    
    //a0 = a0 + a1; b0 = b0 + b1;
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    //z1 = (a0 + a1)(b0 + b1) - z0 - z2;
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    //ret = z0 + z1 * 10^half + z2 * 10^(half/2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}