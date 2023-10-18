#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

//각 판자의 높이

//h[left..right]에서 구할 수 있는 가장 큰 사각형의 넓이
int solve(int left, int right, vector<int>& fence)
{
    //판자가 하나만 있는 경우
    if(left == right) return fence[left];

    //[left, mid], [mid + 1, right]의 두 구간으로 분할
    int mid = (left + right) / 2;

    //case1, 2
    int ret = max(solve(left, mid, fence), solve(mid+1, right, fence));

    //case3
    int lo = mid, hi = mid + 1;
    int height = min(fence[lo], fence[hi]);

    ret = max(ret, height * 2);

    while(left < lo || hi < right)
    {
        if(hi < right && (lo == left || fence[lo - 1] < fence[hi + 1]))//오른쪽 height이 더 높을 때 right sie로
        {
            hi++;
            height = min(height, fence[hi]);
        }
        else//왼쪽 hieght이 높을 때 left side로
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