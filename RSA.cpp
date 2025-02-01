//Names: Thomas Miko 
// Name: Diego Perez Gonzalez

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

int reducer(int base, int exp, int mod, vector<int>& nums){
    if(exp <= 2){
        //return base ^ 2 % mod (account for vector) [nums[i] * nums[i+1} % mod] * [base^2 % mod]
        int returnVal = 1;
        for (int i = 0; i < int(nums.size()); i++){
            //cout <<  nums[i] << " ";
            returnVal = returnVal * nums[i] % mod;
        }
        //cout <<endl << returnVal << " " << base << endl;
        //return (returnVal * (int(pow(base,2)) % mod));
        return ((returnVal) * static_cast<long long>(pow(base,exp))  % mod);


    }
    if(exp % 2 == 0){//is even
        exp = exp /2;
        base = int(pow(base,2)) % mod;
        //cout << base << " " << exp << endl;
        return reducer(base, exp, mod, nums);
    }else{
        nums.push_back(base);
        exp = exp /2;
        base = int(pow(base,2)) % mod;
        //cout << base << " " << exp << endl;
        return reducer(base, exp, mod, nums);
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
        cout << "Public key is not valid!" ;
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
        cout << "Public key is not valid!";
        return 0;
    }
    cout << p << " " << q <<" " <<  phi_n << " ";
    //if extended gcd == 1 then d = alpha
    vector<int> nums(3);
    nums = gcd_extended(e,phi_n,nums);
    int d = nums[1];
    cout << d << endl;
    vector<int> decripted;
    vector<int> nums2;
    for(int i = 0; i < message.size(); i++){
        decripted.push_back(reducer(message.at(i),d,n,nums2));
        nums2.clear();
        cout << decripted.back() << " ";
    }
    cout << endl;
    vector<char> decoder = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','\"',',','.','\''};

    for(int i =0; i < decripted.size(); i++){
        cout << decoder.at(decripted.at(i) -7);
    }
    return 0;
}

