#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "include"

int main() {
    vector<int> s = {1,1,1,2,2,3};
    vector<int> vec;
    vec = solution347_0(s, 2);
    for (auto i : vec) {
        cout << i << "; ";
    }
    cout << endl;
    return 0;
}