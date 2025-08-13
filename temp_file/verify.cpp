#include <iostream>
#include <vector>
#include <string>
#include <windows.h> // For SetConsoleOutputCP
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为UTF-8编码
    cout << "Start confirm your guess." << endl;
    vector<string> tmp;
    cout << "插入前 size: " << tmp.size() << endl; // 输出: 0
    
    tmp.emplace_back(""); // 插入空字符串
    // cout << "插入后 size: " << tmp[0] << endl; // 输出: 1
    
    // // 验证内容：第一个元素是空字符串
    // cout << "第一个元素是否为空: " << (tmp[0].empty() ? "是" : "否") << endl; // 输出: 是
    return 0;
}