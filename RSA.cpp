#include <iostream>
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
    //for testing correct inputs
    // cout << "e = " << e << " n= " << n << endl << "Message = ";
    // for(int i = 0; i < m; i++){
    //     cout << message.at(i) << " ";
    // } 

    //verify public key is valid, must be relatively prime
    int key_gcd = gcd(e,n);
    if(key_gcd != 1){
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    cout << key_gcd << endl;
    return 0;
}

