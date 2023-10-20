#include <iostream>
#include <vector>
#include <string>

using namespace std;

//num[]�� �ڸ��� �ø� ó��
void normalize(vector<int>& num)
{
    num.push_back(0);

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < 0) //������ ����� ó�� -> ī������ ���� �� ���� ����
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
    vector<int> c(a.size() + b.size() + 1, 0);  //������ �ִ� �ڸ���
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); i++)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}

//a += b * (10^k);�� ����
void addTo(vector<int>& a, const vector<int>& b, int k);

//a -= b;�� ���� (a >= b ����) 
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();

    //a�� b���� ª�� ��� ���� �ٲ۴�.
    if(an < bn) {
        return karatsuba(b, a);
    }

    //base case: a�� b�� ����ִ� ���
    if(an == 0 || bn == 0) {
        return vector<int>();
    }

    //base case: a�� ���� ª�� ��� O(n^2) �������� �����Ѵ�.
    if(an <= 50) {
        return multiply(a, b);
    }

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);    //a.begin() ~ (a.begin() + half - 1)
    vector<int> a1(a.begin() + half, a.end());      //(a.begin() + half) ~ (a.end() -1) -> a.end(): �� ��� + 1
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