#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

//�� ������ ����

//h[left..right]���� ���� �� �ִ� ���� ū �簢���� ����
int solve(int left, int right, vector<int>& fence)
{
    //���ڰ� �ϳ��� �ִ� ���
    if(left == right) return fence[left];

    //[left, mid], [mid + 1, right]�� �� �������� ����
    int mid = (left + right) / 2;

    //case1, 2
    int ret = max(solve(left, mid, fence), solve(mid+1, right, fence));

    //case3
    int lo = mid, hi = mid + 1;
    int height = min(fence[lo], fence[hi]);

    ret = max(ret, height * 2);

    while(left < lo || hi < right)
    {
        if(hi < right && (lo == left || fence[lo - 1] < fence[hi + 1]))//������ height�� �� ���� �� right sie��
        {
            hi++;
            height = min(height, fence[hi]);
        }
        else//���� hieght�� ���� �� left side��
        {
            lo--;
            height = min(height, fence[lo]);
        }

        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(void)
{
    int cases;
    cin >> cases;
    assert(cases <= 50);

    while(cases--)
    {
        int fenceNum;
        cin >> fenceNum;
        assert(fenceNum <= 20000 && fenceNum >= 1);

        vector<int> fence(fenceNum);
        for(int i = 0; i < fenceNum; i++)
        {
            cin >> fence[i];
            assert(fence[i] <= 10000 && fence[i] >= 0);
        }
        cout << solve(0, fence.size()-1, fence) << endl;
    }

    return 0;
}