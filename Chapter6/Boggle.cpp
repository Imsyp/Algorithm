#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point
{
    public:
        int x;
        int y;
        char data;

        void initPoint(int x, int y, char data)
        {
            x = this -> x;
            y = this -> y;
            data = this -> data;
        }

        char getSpell(int y, int x)
        {
            this->x
        }
};

bool inRange(int y, int x)
{
    if(!(y<6) || !(x<6))
        return false;
    else
        return true;
}



bool hasWord(int y, int x, const string& word)
{
    if(!inRange(y, x))
        return false;

    if(getSpell(y, x) != word[0])
        return false;   
    else if(word.size() == 1)
        return true;
    else
    {
        for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++)
                if(hasWord(y+i, x+j, word.substr(1)))
                    return true;
    }

    return false;
}