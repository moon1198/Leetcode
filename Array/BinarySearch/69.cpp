
int solution69_0(int x){
    //bugy code
   int left = 0;
   int right = x;
   int mid = 0;
   if (x < 0){
        return -1;
   }
   while(left <= right) {
        mid = (left + right) / 2;
        if (mid * mid > x){
            right = mid - 1;
        }
        else if (mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x)){
            return mid;
        }
        else{
            left = mid + 1;
        }
   }
   return -1;
}
int solution69_1(int x){
    unsigned int left = 1;
    unsigned int right = x;
    unsigned int mid = 0;
    if (x < 0){
        return -1;
    }else if (x == 0){
        return 0;
    }
    while(left <= right){
        mid = (left + right) / 2;
        if (x / mid == mid || (x / mid > mid && x / (mid + 1) < (mid + 1))){         //mid < target
            return mid;
        }
        else if (x / mid < mid){      //mid > target
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}