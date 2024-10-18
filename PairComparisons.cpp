#include<iostream>
#include<set>
using namespace std;
int reveal(int x)
{
    return x;
}
const int N = 100010;
bool match[N];
Algorithm set PairwiseComparisions(set S, set S')
{
    for(int i = 1; i <= S'.size(); i++)
        match[i] = false;
    for(int i = 1; i <= S.size(); i++)
        for(int j = 1; j <= S'.size(); j++)
            if(!match[j] && (Equal(S[i], S'[j])))
            {
                reveal(S[i]);
                match[j] = true;
                break;
            }
}
