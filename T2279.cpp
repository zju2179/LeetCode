#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
{
    vector<int> a;
    int n = capacity.size();
    for (int i = 0; i < n; i++)
    {
        int gap = capacity[i] - rocks[i];
        a.push_back(gap);
    }
    int res = 0;
    sort(a.begin(), a.end());
    for (int gap : a)
    {
        if (additionalRocks >= gap)
        {
            additionalRocks -= gap;
            res++;
        }
    }
    return res;
}
void Enc(string s)
{
    for (char c : s)
    {
        char x = ('a' + (c - 'a' + 3) % 26);
        cout << x;
    }
    cout << endl;
}
int main()
{
    Enc("lovezju"); 
    return 0;
}