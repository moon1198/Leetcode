#include <vector>
using namespace std;
int solution27_0(vector<int> &nums, int val){
    auto size = nums.size();
    vector<int>::iterator bg_right = nums.begin();
    auto ed = nums.end();
    auto bg_left = bg_right;
    for(; bg_right != ed; bg_right ++){
        if (*bg_right != val){
            *bg_left = *bg_right;
            bg_left ++;
        }
    }
    size = size - (bg_right - bg_left);
    nums.erase(nums.begin() + size, nums.end());
    return size;
}