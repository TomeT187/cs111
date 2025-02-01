//Names: Thomas Miko 
// Name: Diego Perez Gonzalez

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int reducer(int base, int exp, int mod, vector<int>& nums){
    if(exp <= 2){
        //return base ^ 2 % mod (account for vector) [nums[i] * nums[i+1} % mod] * [base^2 % mod]
        int returnVal = 1;
        for (int i = 0; i < int(nums.size()); i++){
            cout <<  nums[i] << " ";
            returnVal = returnVal * nums[i] % mod;
        }
        cout <<endl << returnVal << " " << base << endl;
        //return (returnVal * (int(pow(base,2)) % mod));
        return ((returnVal) * static_cast<long long>(pow(base,exp))  % mod);


    }
    if(exp % 2 == 0){//is even
        exp = exp /2;
        base = int(pow(base,2)) % mod;
        cout << base << " " << exp << endl;
        return reducer(base, exp, mod, nums);
    }else{
        nums.push_back(base);
        exp = exp /2;
        base = int(pow(base,2)) % mod;
        cout << base << " " << exp << endl;
        return reducer(base, exp, mod, nums);
    }
}

int main(){
    vector<int> nums;
    cout << reducer(13,7,55,nums);
    return 0;
}