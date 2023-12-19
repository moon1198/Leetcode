#include <vector>
using std::vector;
int solution904_0(vector<int>&fruits){
    int basket1 = -1;    
    int basket2 = -1;    
    int count = 0;
    int temp = 0;
    int right = 0; int left = 0;
    int len = fruits.size();
    //init
    basket1 = fruits[0];
    while (fruits[right] == basket1){
        ++ right;
        if(right == len){
            return len;
        }
    }
    basket2 = fruits[right ++];
    temp = right;
    //iterator
    for (;right < len; ++ right){
        if (fruits[right] == basket1 || fruits[right] == basket2){
            temp ++;
        }else{
            left = right - 1;
            if (fruits[left] == basket1){
                while (fruits[left] == basket1){
                    -- left;
                }
                basket2 = fruits[right];
                count = temp > count ? temp : count;
                temp = right - left;
            }else{
                while (fruits[left] == basket2){
                    -- left;
                }
                basket1 = fruits[right];
                count = temp > count ? temp : count;
                temp = right - left;
            }
        }
    }
    count = temp > count ? temp : count;
    return count;
}