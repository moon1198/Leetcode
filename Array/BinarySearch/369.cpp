bool solution369_0(int num){
    int left = 1;
    int mid = 0;
    int right = num / 2 + 1;
    if (num == 0){
        return true;
    }
    while (left <= right){
        mid = (left + right) / 2;
        if (num / mid < mid){       //mid > target
            right = mid - 1;
        }else if (num / mid > mid){     //mid < target
            left = mid + 1;
        }else if (mid * mid == num){       //mid == target,target / mid == mid
            return true;
        }else{
            return false;
        }
    }
    return false;
}