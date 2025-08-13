#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2(8, 4);
    for (int i = 0; i < v.size(); i++) { 
        std::cout << v[i] << std::endl;
    }
    v2.push_back(5);
    sort(v.begin(), v.end());
    return 0;
}