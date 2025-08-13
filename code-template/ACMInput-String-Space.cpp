// 描述
// 给定 t 组询问，每次给出一个长度为 n 的带空格的字符串 s ，请你去掉空格之后，将其倒置，然后输出。
// 输入描述：
// 每组的第一行有一个整数 t。 随后 t 组数据。每组的第一行有一个整数 n
// 每组的第二行有一个字符串 s，仅包含小写英文字符和空格，保证字符串首尾都不是空格。
// 输出描述：
// 输出 t 行，每行一个字符串，代表倒置后的字符串 s 。
// 示例1
// 输入：
// 3
// 9
// one space
// 11
// two  spaces
// 14
// three   spaces
// 输出：
// ecapseno
// secapsowt
// secapseerht

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin.ignore();
        string s;
        getline(cin, s);
        cout<<s<<endl;
        
        string filtered;
        for(char c: s){
            if(c != ' '){
                filtered.push_back(c);
            }
        }
        reverse(filtered.begin(), filtered.end());
        cout<<filtered<<endl;
    }
    return 0;
}