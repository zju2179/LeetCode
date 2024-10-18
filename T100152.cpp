#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isNeighbor(char a, char b)
{
    if(abs(a - b) == 1)
        return true;
    else    
        return false;
}

int removeAlmostEqualCharacters(string word) {
    int res = 0;
    int i = 0, n = word.length();
    while(i < n)
    {
        int st = i;
        i++;
        while(i < n && isNeighbor(word[i], word[i-1]))
            i++;
        res += (i - st)/2;
    }
    return res;
}

int main()
{
    string word = "abddez";
    cout<<removeAlmostEqualCharacters(word)<<endl;
    return 0;
}