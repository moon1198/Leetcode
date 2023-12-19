#include <vector>
#include <iostream>
using namespace std;
int soulution_34_0(){
    vector<int> nums {1, 3, 4, 4, 4, 4, 5 ,6};
    int target = 4;
    int left = 0;
    int mid = 0;
    int size = nums.size();
    int right = size - 1;
    int tar = -1;

    int left_tar = 0;
    int right_tar = 0;
    while(left <= right){
        mid = (left + right) / 2;
        if (target < nums[mid]){
            right = mid - 1;
        }
        else if (target > nums[mid]){
            left = mid + 1;
        }else{
            tar = mid;
            break;
        }
    }
    if (tar == -1){
        cout << "{-1, -1}";
        return 0;
    }else{
        left = 0;
        right = tar;
        left_tar = tar;
        while(left <= right){
            mid = (left + right) / 2;
            if (target > nums[mid]){
                left = mid + 1;
            }else if (target == nums[mid]){
                left_tar = mid;
                right = mid - 1;
            }
        }
        left = tar;
        right = size - 1;
        right_tar = tar;
        while(left <= right){
            mid = (left + right) / 2;
            if (target < nums[mid]){
                right = mid - 1;
            }else if (target == nums[mid]){
                left = mid + 1;
                right_tar = mid;
            }
        }
    }
    cout << "{" << left_tar << ", " << right_tar << "}" << endl;
    return 0;
}
