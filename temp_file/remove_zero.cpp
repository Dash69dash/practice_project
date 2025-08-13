#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

// 移除小数末尾的零
std::string removeTrailingZeros(const std::string& numStr) {
    std::string result = numStr;
    size_t dotPos = result.find('.');
    if (dotPos != std::string::npos) {
        size_t lastNonZero = result.find_last_not_of('0');
        if (lastNonZero != std::string::npos && lastNonZero > dotPos) {
            if (result[lastNonZero] == '.') {
                result.erase(lastNonZero);
            } else {
                result.erase(lastNonZero + 1);
            }
        }
    }
    return result;
}

// 处理双精度浮点数，去除末尾零
std::string processDouble(double num) {
    std::cout << "进入processDouble..." << std::endl;
    std::ostringstream oss;
    oss.precision(4);
    oss << std::fixed << num;
    std::cout << oss.str() << std::endl;
    // return removeTrailingZeros(oss.str());
    return "";
}

int main() {
    std::cout << "start开始运行..." << std::endl;
    double numbers[] = {5.7300, 23.9000, 2.3300};
    for (double num : numbers) {
        std::string processed = processDouble(num);
        // std::cout << num << " -> " << processed << std::endl;
        std::cout << std::fixed << std::setprecision(4);
        std::cout << num << std::endl;
    }
    std::cout.flush(); // 确保所有输出都被刷新到控制台
    std::string file_name = "F:\Code_myself\VsStudio\temp_porject";
    file_name.substr
    return 0;
}