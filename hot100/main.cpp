#include "include.h"


int main() {
    vector<vector<int>> edges = {{3},{2}};
    string s = "bbbbb";
    vector<int> nums = {1,3,5,6};
    
    for (auto ch : "()") {
        if (ch == '\0') {
            cout << "1" << endl;
        }
    }
    // bar();
    searchInsert(nums, 2);
    return 0;
}