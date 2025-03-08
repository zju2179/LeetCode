// 对输入的字符串进行排序后输出
// 输入描述：
// 多个测试用例，每个测试用例一行。

// 每行通过空格隔开，有n个字符，n＜100
// 输出描述：
// 对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
// 示例1
// 输入例子：
// a c bb
// f dddd
// nowcoder
// 输出例子：
// a bb c
// dddd f
// nowcoder
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        istringstream iss(line);
        string word;
        vector<string> words;
        while(iss >> word){
            words.push_back(word);
        }
        sort(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++){
            cout<<words[i];
            if(i < words.size() - 1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}