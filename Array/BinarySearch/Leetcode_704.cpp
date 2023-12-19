#include <vector>
using std::vector;
int soultion_704_0 (){
    vector<int>  nums = {-2, 0, 3, 5, 9, 12};
    int target =  12;
    int left = 0;
    int right =  nums.size() - 1;
    int mid = 0;
    while (left <= right){
        mid = (left + right) / 2;
        if (target < nums[mid]){
            right = mid - 1;
        }
        else if (target > nums[mid]){
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
    }
int soultion_704_1 (){
    vector<int>  nums = {-1, 0, 3, 5, 9, 12};
    int target =  12;
    int left = 0;
    int mid = 0;
    int right =  nums.size();
    while (left < right){
        mid = (left + right) / 2;
        if (target < nums[mid]){
            right = mid;
        }
        else if (target > nums[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
