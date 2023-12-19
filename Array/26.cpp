#include <vector>
using namespace std;
int solution26_0(vector<int> & nums) {
    auto ptr_left = nums.begin();
    auto ptr_right = nums.begin();
    int pre = *ptr_right;
    ++ ptr_right;
    ++ ptr_left;
    for (; ptr_right != nums.end(); ++ ptr_right){
        if (*ptr_right != pre){
            *ptr_left = *ptr_right;
            ++ ptr_left;
            pre = *ptr_right;
        }
    }
    return ptr_left - nums.begin();
}