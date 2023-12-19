#include <iostream>
using namespace std;
void fcn3() {
    size_t v1 = 42;
    auto f = [v1] () mutable {return ++v1;};
    // v1 = 0;
    auto j = f();
    cout << "j = " << j << "  " << "v1 = " << v1 << endl;
}