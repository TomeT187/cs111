#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return(gcd(b%a, a));
}

//verify the size of nums is correct before calling
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
    //take 4 inputs, 3 ints and the message as a vector of ints
    int e, n,m;
    cin >> e >> n;
    cin >> m;

    vector<int> message;
    int placeholder;
    for (int i = 0; i < m; i++){
        cin >> placeholder;
        message.push_back(placeholder);
    }

    //verify public key is valid, must be relatively prime
    int key_gcd = gcd(e,n);
    if(key_gcd != 1 || n <= 0){
        cout << "Public key is not valid!" << endl;
        return 0;
    }

    //find all prime numbers less sqrt(n) and check which ones are factors of n those 2 are p and q
    vector<int> primes;
    bool isPrime;
    for(int i = 0; i < n; i++ ){
        isPrime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                isPrime = false;
            }
        }
        if(isPrime){
            primes.push_back(i);
            
        }
    }
    int p,q;
    for(int i = 0; i < int(primes.size()); i++){
        for(int j = 0; j < int(primes.size()); j++){
            if (i * j == n && i < j){
                //cout << i << "*" << j << "=" << n << endl;
                p = i;
                q = j;
            }
        }
    }
    //p cannot equal q, phi_n must be coprime with e
    int phi_n = (p-1) * (q-1);
    if(gcd(e,phi_n) != 1 || p == q){
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    cout << p << " " << q <<" " <<  phi_n << " ";
    //if extended gcd == 1 then d = alpha
    vector<int> nums(3);
    nums = gcd_extended(e,phi_n,nums);
    cout << nums[1] << endl;
    return 0;
}

