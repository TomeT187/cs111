#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int>& gcd_extended(int a, int b, vector<int>& nums){
    if(a == b){
        nums.at(0) = a;
        nums.at(1) = 1;
        nums.at(2) = 0;
        return nums;
    }
    if(a > b){
        nums = gcd_extended(a-b,b, nums);
        nums.at(2) = nums.at(2) - nums.at(1);
        return nums;
    }else{
        nums = gcd_extended(a, b-a,nums);
        nums.at(1) = nums.at(1) - nums.at(2);
        return nums;
    }
}

int main(){
    vector<int> nums(3);
    nums = gcd_extended(23,40,nums);
    cout << nums[0] <<" "<< nums[1] <<" " << nums[2] << endl;

    return 0;
}