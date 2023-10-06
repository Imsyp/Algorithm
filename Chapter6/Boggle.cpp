#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hasWord(int y, int x, vector<string>& word)
{
    int TRUE = 1;
    int FALSE = 0;

    
    if(getSpell(y, x) != word[location])
        return FALSE;   
    else if(word.size() == 0)
        return TRUE;
    else
    {
        for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++)
                hasWord(y+i, x+j, word)
    }
}