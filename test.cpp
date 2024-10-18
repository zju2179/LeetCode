#include <iostream>
#include <cmath>
#include <algorithm>
// using namespace std;
using std::cin;
using std::cout;
using std::endl;
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void ChooseSort(T a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int max_i = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[max_i] < a[j])
            {
                max_i = j;
            }
        }
        if (max_i != i)
        {
            mySwap(a[max_i], a[i]);
        }
    }
}

template <typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void test()
{
    // char charArr[] = "badcfe";
    // int len = sizeof(charArr) / sizeof(char);
    // ChooseSort<char>(charArr, len);
    // printArray(charArr, len);

    int a[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
    int len = sizeof(a) / sizeof(int);
    ChooseSort(a, len);
    printArray(a, len);
}

int main()
{
    int x;
    cin >> x;
    double res = M_E - pow(1.0 + 1.0 / (double)x, (double)x);
    cout << res << endl;
    return 0;
}