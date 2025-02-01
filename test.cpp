//Names: Thomas Miko 
// Name: Diego Perez Gonzalez

#include <iostream>
#include <vector>
using namespace std;

int func(int base, int exp, int mod, vector<int> nums){
    if(exp <= 2){
        //return base ^ 2 % mod (account for vector) [nums[i] * nums[i+1} % mod] * [base^2 % mod]
    }
    if(exp % 2 == 0){//is even
        exp = exp /2;
        base = base ^ 2 % mod;
        func(base, exp, mod, nums)
    }else{
        nums.push_back(base);
        exp = exp /2;
        base = base ^ 2 % mod;
        func(base, exp, mod, nums);
    }
}

int main(){
    cout << (2^2) << endl;
    return 0;
}