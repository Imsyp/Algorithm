#include <iostream>

using namespace std;

int main(void)
{
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            cout << i << "," << j << endl;
        }
    }

    return 0;
}