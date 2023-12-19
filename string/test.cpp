#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;
int test() {
    vector<int>vec = {1, 2, 3, 4 , 5, 6, 7};
    while (vec.capacity() < 10000) {
        while (vec.size() != vec.capacity()) {
            vec.push_back(0);
        }
        cout << "capacity = " << vec.capacity() << endl;
        vec.push_back(0);
    }
    return 0;
}