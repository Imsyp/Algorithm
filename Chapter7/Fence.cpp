#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int leftArea(const vector<int>& fence, int cur)
{
    if(cur == 0)
        return 0;


    int area = 0;
    for(int back = cur-1; back>=0; back--)
    {
        if(fence[back] < fence[cur])
            break;
        area += fence[cur];
    }

    return area;
}

int rightArea(const vector<int>& fence, int cur)
{
    if(cur == fence.size() - 1)
        return 0;

    int area = 0;
    for(int front = cur+1; front < fence.size() ; front++)
    {
        if(fence[front] < fence[cur])
            break;
        area += fence[cur];
    }

    return area;
}

int maxArea(const vector<int>& fence)
{
    int answer = 0;
    for(int cur = 0; cur < fence.size() - 1; cur++)
    {
        int curArea = leftArea(fence, cur) + rightArea(fence, cur) + fence[cur];
        answer = max(curArea, answer);
    }

    return answer;
}

//��ȿ��� ���� Ǭ ���
int bruteForce(const vector<int>& h)
{
    int ret = 0;
    int N = h.size();

    //������ ��� left, right ���� ��ȸ
    for(int left = 0; left < N; left++)
    {
        int minHeight = h[left];
        for(int right = left; right < N; right++)
        {
            minHeight = min(minHeight, h[right]);
            ret = max(ret, (right - left + 1) * minHeight);
        }
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
        cout << bruteForce(fence) << endl;
    }

    return 0;
}