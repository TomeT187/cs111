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
    if(key_gcd != 1){
        cout << "Public key is not valid!" << endl;
        return 0;
    }

    //find all prime numbers less sqrt(n) and checek which ones are factors of n those 2 are p and q
    vector<int> primes;
    int a;
    for(int i = 0; i < int(sqrt(n)); i++ ){
        cout << i << endl;
        //pick an int a st gcd(i,a) = 1
        a = 1;
        // while(gcd(i,a) != 1){
        //     a++;
        // }
        //check if a^(i-1) % i = 1
        //cout << i << a << endl;
        if((a^(i-1) % i) == 1){ // a^i-1 ≡ 1 (mod i);
            primes.push_back(i);
        }
    }
    for(int i = 0; i < int(primes.size()); i++){
        cout << primes.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}

