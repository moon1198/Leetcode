#include <vector>
using namespace std;
int soulution_35_0(){
    vector<int> nums {1, 3, 5 ,6};
    int target = 7;
    int left = 0;
    int mid = 0;
    int size = nums.size();
    int right = size;
    while (left < right){
        mid = (left + right) / 2;
        if (target < nums[mid]){
            right = mid;
        }
        else if (target > nums[mid]){
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    if (left == size){
        return size;
    }
    else if (target > nums[left]){
        return left + 1;
    }else{
        return left;
    }
}